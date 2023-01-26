#include <bits/stdc++.h>
void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}
typedef struct array {
  int first, second;
} point;
long long int min(long long int a, long long int b) { return a < b ? a : b; }
long long int max(long long int a, long long int b) { return a > b ? a : b; }
int cmpfunc(const void* a, const void* b) {
  return (*(long long int*)a - *(long long int*)b);
}
int comp(const void* a, const void* b) {
  long long i = *(long long*)a;
  long long j = *(long long*)b;
  return (int)((i > j) - (i < j));
}
int partition(int array[], int index[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
      swap(&index[i], &index[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  swap(&index[i + 1], &index[high]);
  return (i + 1);
}
void quickSort(int array[], int index[], int low, int high) {
  if (low < high) {
    int pi = partition(array, index, low, high);
    quickSort(array, index, low, pi - 1);
    quickSort(array, index, pi + 1, high);
  }
}
void test();
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    test();
  }
}
void test() {
  int n, i, p;
  scanf("%d", &n);
  for (i = 1; i <= 100002; i++) {
    if (i * i >= n) {
      p = i;
      break;
    }
  }
  n -= (p - 1) * (p - 1);
  if (n <= p) {
    printf("%d %d\n", n, p);
  } else {
    n -= p;
    printf("%d %d\n", p, p - n);
  }
}
