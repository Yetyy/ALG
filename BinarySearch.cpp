#include <iostream>
using namespace std;

int binarySearch(int* arr, int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int binary_search_r(int* array, int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (array[mid] == target) {
        return mid;
    }
    else if (array[mid] < target) {
        return binary_search(array, mid + 1, right, target);
    }
    else {
        return binary_search(array, left, mid - 1, target);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    int index = binarySearch(arr, n, key);
    if (index == -1)
        cout << key << " not found in the array." << endl;
    else
        cout << key << " found at index " << index << endl;
    return 0;
}