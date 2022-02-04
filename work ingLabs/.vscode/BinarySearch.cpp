#include <iostream>
#include <string>

//BinarySearch function which uses the divide and conquer 
int BinarySearch(int arr[], int length, int key)
{
    //declare necessary variables
    bool found;
    int low= 0;
    int high = length -1;
    int mid = 0;
    //searchData was declared to see what value key was holding for debugging
    int searchData = key;

    //this loop will continuously run until the condition is rendered false
    while(low <= high && !found)
    {
        //since mid variable is an integer, the value of the computation automatically truncates
        //mid will continuosly keep updating itself until the while loop breaks
        mid = (low + high) / 2;

        //if search data larger then mid, set new low to the next element ahead of mid
        if( searchData > arr[mid])
        {
            low = mid + 1;
        }
        //if search data is less than mid, set new high to the element 1 lower than current mid
        else if (searchData < arr[mid])
        {
            high = mid - 1;
        }
        //this code means the seachdata variable has found the intended value and will return it 
        //Also will change the bool variable to true, essentially allowing the while loop to break out
        else
        {
            found = true;
            return mid;
        }
    }

    //method returns -1 if the key is never found
    return -1;
};

using namespace std;

int main()
{
    //declare necessary attributes to call function and set array
    int size;
    int* arr;
    int key;
    //declare variables to assist on sorting, gathering and displaying data
    int input;
    int temp;
    int value;
    

    //prompt user to enter the size of array
    cout << "Enter an integer to initialize size of array: " << endl;
    cin >> size;

    //resize array based on user input
    arr = new int[size];

    //prompt user to fill array
    cout << "Please enter integers to fill array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    //prompt user to enter in key
    cout << "Please enter an integer KEY: " << endl;
    cin >> key;

    //sort the array least to greatest
    cout << "Now sorting array..." << endl;
    for (int i = 0; i < size; i++) //allows access to first element
    {
        for (int j = i+1; j < size; j++) // allows access to next element
        {
            //logic for switching the values using temp variable
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }     
    }

    //inform user the current status of program
    cout << "Here is sorted the array: " << endl;

    //print out array to see data
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //inform user the current status of program
    cout << "\nNow Performing Binary search..." << endl;

    //call the function and save value into variable
    value = BinarySearch(arr, size, key);

    //logic for printing out value found using binary search along with helpful info
    if (value != -1)
    {
        cout << "The key was found at index: " << value << " during Binary Search. " << endl;
    }
    //logic for informing user that their key was not in the array
    else
    {
        cout << "ERROR: Key not found in the Array (RETURN -1) ..." << endl;
        cout<< value << endl;
    }

    return 0;
}