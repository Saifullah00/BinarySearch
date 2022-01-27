#include <bits/stdc++.h>
using namespace std;

/* Binary Search only in Sorted Array --> T = O(logn) */

// iterative methods
int Binary_search_iterative(vector<int> &v, int search, int start, int end)
{
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (v[mid] == search)
      return mid;
    if (v[mid] < search) // x is on the right side
    {
      start = mid + 1;
    }
    else // x is on the left side
    {
      end = mid - 1;
    }
  }
  return -1;
}

// Recursive methods
int Binary_search_Recursive(vector<int> &v, int x, int low, int high)
{
  if (high >= low)
  {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (v[mid] == x)
      return mid;

    // Search the left half
    if (v[mid] > x)
      return Binary_search_Recursive(v, x, low, mid - 1);

    // Search the right half
    return Binary_search_Recursive(v, x, mid + 1, high);
  }

  return -1;
}

// First and Last Occurence of a given number
int Occurence_of_First_Ele(vector<int> &v, int ele, int start, int end)
{
  int res = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (ele == v[mid])
    {
      res = mid;
      end = mid - 1; // For first occurence
      // start = mid + 1; // for Last occurence
    }
    else if (ele < v[mid])
    {
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return res;
}
int Occurence_of_Last_Ele(vector<int> &v, int ele, int start, int end)
{
  int res = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (ele == v[mid])
    {
      res = mid;
      // end = mid -1; // For first occurence
      start = mid + 1; // for Last occurence
    }
    else if (ele < v[mid])
    {
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return res;
}

// Counting of an element in Array
int Count_Ele(vector<int> &v, int ele, int start, int end)
{
  /* To count element --> (lastOcuurence - firstOccurence) + 1 = count */
  int count = -1;
  int Last_occ = Occurence_of_Last_Ele(v, ele, start, end);
  int first_occ = Occurence_of_First_Ele(v, ele, start, end);
  if (Last_occ && first_occ != -1)
    count = (Last_occ - first_occ) + 1;

  return count;
}

int main()
{
  vector<int> v{1, 2, 4, 5};
  int search = 3;
  int end = v.size(); // int end = sizeof(arr) / sizeof(arr[0]);
  // int result = Binary_search_iterative(v, search, 0, end -1);
  // int result = Binary_search_Recursive(v, search, 0, end -1);
  // int result = Occurence_of_First_Ele(v, search, 0, end - 1);
  /* (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element is present at index " << result; */
  int result = Count_Ele(v, search, 0, end - 1);
  (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element occur " << result << " times in array";
}