#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}
int minimum(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] < min) min = arr[i];
  return min;
}
int maximum(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max) max = arr[i];
  return max;
}
int maxSubarraySum(int arr[], int n) {
  int ms = INT_MIN;
  int me = 0;
  int start = 0;
  int end = 0;
  int s = 0;
  for (int i = 0; i < n; i++) {
    me += arr[i];
    if (me > ms) {
      ms = me;
      start = s;
      end = i;
    }
    if (me < 0) {
      me = 0;
      s = i + 1;
    }
  }
  return ms;
}
bool sortcol(const vector<int>& v1, const vector<int>& v2) {
  return v1[0] < v2[0];
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    ;
    sort(arr, arr + n);
    int siz = n / 2;
    for (int i = 1; i <= siz; i++) {
      cout << arr[i] << " " << arr[0] << endl;
    }
  }
  return 0;
}
