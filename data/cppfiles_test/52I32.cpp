#include <bits/stdc++.h>
using namespace std;
int maxx(int arr[], int size) {
  int maximum;
  maximum = max_element(arr, arr + size) - arr;
  return maximum;
}
int maxx(int arr[], int size);
int cyc_shift(int arr[], int arr_start, int arr_end) {
  int temp = arr[arr_start];
  for (int i = arr_start; i < arr_end; ++i) {
    arr[i - 1] = arr[i];
  }
  arr[arr_end - 1] = temp;
  return 0;
}
int cyc_shift(int arr[], int arr_start, int arr_end);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      a[j] = temp;
    }
    int count = 0;
    for (int j = 0; j < n; j++) {
      if ((n - j - 1) != maxx(a, n - j)) count++;
    }
    cout << count << endl;
    for (int j = 0; j < n; j++) {
      if ((n - j - 1) != (maxx(a, n - j))) {
        int l, r;
        l = maxx(a, n - j);
        r = n - j - 1;
        cout << l << " ";
        cout << r << " ";
        cout << "1" << endl;
        cyc_shift(a, l, r);
      }
    }
  }
}
