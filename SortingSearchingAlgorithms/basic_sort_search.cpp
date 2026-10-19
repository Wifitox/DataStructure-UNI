/*
Act 1-2 Search & sorting algorithms
A01647837
07/09/2026
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// bubbleSort
// Sorts the vector in ascending order using the bubble sort algorithm.
// Parameters:
//   v - the vector to sort; gets modified directly.
// Returns: nothing (void).
// Complexity: O(n^2)
template <typename T>
void bubbleSort(vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// selectionSort
// Sorts the vector in ascending order using the selection sort algorithm.
// Parameters:
//   v - the vector to sort; gets modified directly.
// Returns: nothing (void).
// Complexity: O(n^2)
template <typename T>
void selectionSort(vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(v[i], v[minIdx]);
        }
    }
}

// insertionSort
// Sorts the vector in ascending order using the insertion sort algorithm.
// Parameters:
//   v - the vector to sort; gets modified directly.
// Returns: nothing (void).
// Complexity: O(n^2)
template <typename T>
void insertionSort(vector<T>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}


// sequentialSearch
// Looks for target by scanning the vector from the start.
// Parameters:
//   v      - the vector to search in.
//   target - the value being looked for.
// Returns: the index of target if found, or -1 if it is not present.
// Complexity: O(n)
template <typename T>
int sequentialSearch(const vector<T>& v, const T& target) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}

// binarySearch
// Looks for target by repeatedly reducing the search range.
// Parameters:
//   v      - the vector to search in; must already be sorted ascending.
//   target - the value being looked for.
// Returns: the index of target if found, or -1 if it is not present.
// Complexity: O(log n)
template <typename T>
int binarySearch(const vector<T>& v, const T& target) {
    int low = 0;
    int high = (int)v.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// printVector
// Prints a vector's contents to standard output, preceded by a label.
// Parameters:
//   label - text printed before the values.
//   v     - the vector whose contents are printed.
// Returns: nothing (void).
template <typename T>
void printVector(const string& label, const vector<T>& v) {
    cout << label << ": ";
    for (const T& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

/*
Hard-codes a test vector and a search value, runs bubbleSort, selectionSort and insertionSort, on its own independent copy of the vector.
Prints the three sorted results, then runs sequentialSearch and binarySearch for search a value on the sorted vector and prints the results.
Parameters: none.
Returns: 0.
*/
int main() {
    vector<int> vectorNumeros = {29, 10, 14, 37, 10, 5, 22, 18};
    int searchValue = 22;


    // A copy for each method
    vector<int> vBubble = vectorNumeros;
    vector<int> vSelection = vectorNumeros;
    vector<int> vInsertion = vectorNumeros;
 
    bubbleSort(vBubble);
    selectionSort(vSelection);
    insertionSort(vInsertion);
 
    printVector("bubbleSort", vBubble);
    printVector("selectionSort", vSelection);
    printVector("insertionSort", vInsertion);
 
    int seqIndex = sequentialSearch(vBubble, searchValue);
    int binIndex = binarySearch(vBubble, searchValue);
 
    cout << "sequentialSearch: index of " << searchValue << " = " << seqIndex << endl;
    cout << "binarySearch: index of " << searchValue << " = " << binIndex << endl;
 
    return 0;
}