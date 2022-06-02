#include <iostream>
using namespace std;

const int n = 10;

struct ToSort {
    int key;
    char info;
};

void fillStruct(ToSort*);
int findpivot(int, int, ToSort*);
int partition(int, int, int, ToSort*);
void quicksort(int, int, ToSort*);
void printStruct(ToSort*);

int main() {
    ToSort* A = new ToSort[n];
    fillStruct(A);
    cout << "Unsorted struct array: " << endl;
    printStruct(A);
    cout << endl << endl << "Sorted struct array with quick sort: " << endl;
    quicksort(0, n-1, A);
    printStruct(A);
    return 0;
}

void fillStruct(ToSort* A) {
    srand(time(0));
    int r;
    for (int i = 0; i < n; i++) {
        r = rand() % 26;
        A[i].info = 'a' + r;
        A[i].key = rand() % 10;
    }
}

int findpivot(int i, int j, ToSort* A) {
    int fk;
    fk = A[i].key;
    for (int k = i + 1; k <= j; k++) {
        if (A[k].key > fk)
            return k;
        else if (A[k].key < fk)
            return i;
    }
    return -1;
}

int partition(int i, int j, int pivot, ToSort* A) {
    int l, r;
    l = i;
    r = j;
    do {
        swap(A[l], A[r]);
        while (A[l].key < pivot)
            l++;
        while (A[r].key >= pivot)
            r--;
    } while (l <= r);
    return l;
}

void quicksort(int i, int j, ToSort* A) {
    int pivot;
    int pivotindex;
    int k;
    pivotindex = findpivot(i, j, A);
    if (pivotindex != -1) {
        pivot = A[pivotindex].key;
        k = partition(i, j, pivot, A);
        quicksort(i, k - 1, A);
        quicksort(k, j, A);
    }
}

void printStruct(ToSort* A) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << A[i].key<<"|" << A[i].info;
        if (i < n - 1)
            cout << "; ";
    }
    cout << "]";
}
