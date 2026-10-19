#include <iostream>
#include <vector>

using namespace std;


template <typename T>
int partition(vector<T>& v, int inicio, int final){

    T pivote = v[final];

    int i = inicio - 1;

    for(int j = inicio; j < final; j++){
        if(v[j] <= pivote){
            i++;
            swap(v[j],v[i]);
        }
    }

    swap(v[i+1],v[final]);

    return i + 1;
}

template <typename T>
void quickSort(vector<T>& v, int inicio, int final){

    if(inicio>=final){
        return;
    }

    int posPivote = partition(v,inicio,final);

    quickSort(v, inicio, posPivote - 1);

    quickSort(v, posPivote + 1, final);

}


template <typename T>
void bubbleSort(vector<T>& v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(v[j]> v[j + 1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

template <typename T> 
int sequentialSearch(const vector<T>& v, const T& target){
    for( int i = 0; i < v.size(); i++){
        if(v[i] == target){
            return i;
        }
    }

    return -1;
}

template <typename T>
int binarySearch(const vector<T>& v, const T& target){

    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
       int mid = low + (high - low) / 2; 

       if(v[mid] == target){
        return mid;
       }
       else if (v[mid] < target){
        low = mid + 1;
       }
       else {
        high = mid - 1;
       }    
    }
    return -1;
}

template <typename T>
void imprimirVector(const vector<T>& v){
    for(const T& num : v){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> datos = {29, 10, 14, 37, 10, 5, 22, 18};

    vector<int> vectorQuickSort = datos;
    vector<int> vectorBubbleSort = datos;

    imprimirVector(datos);
    quickSort(vectorQuickSort, 0, vectorQuickSort.size() - 1);
    bubbleSort(vectorBubbleSort);
    imprimirVector(vectorQuickSort);
    imprimirVector(vectorBubbleSort);

    int numSearch = 22;

    int seqIndex = sequentialSearch(vectorQuickSort, numSearch);
    int binIndex = binarySearch(vectorQuickSort, numSearch);
    cout << "Sequential Search: " << numSearch << " element at index: " << seqIndex << endl;
    cout << "Binary Search: " << numSearch << " element at index: " << binIndex << endl;

return 0;
}