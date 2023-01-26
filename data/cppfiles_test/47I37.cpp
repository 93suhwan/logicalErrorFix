#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int q = 0; q < t; q++) {
    long long int n;
    long long int k;
    cin >> n;
    cin >> k;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    bool goleft;
    if (abs(arr[0]) >= abs(arr[n - 1]) && arr[0] < 0)
      goleft = true;
    else {
      goleft = false;
    }
    if (goleft) {
      long long int lptr = k;
      long long int rptr = n - 1;
      long long int dist = 0;
      long long int negative = -1;
      long long int positive = -1;
      for (long long int i = 0; i < n; i++) {
        if (arr[i] < 0) {
          negative = i;
        }
      }
      for (long long int i = n; i >= 0; i--) {
        if (arr[i] > 0) {
          positive = i;
        }
      }
      if (positive != -1)
        while (rptr >= positive) {
          dist += (arr[rptr] * 2);
          rptr -= k;
        }
      while (lptr > k) {
        dist += (abs(arr[lptr]) * 2);
        lptr -= k;
      }
      dist += abs(arr[0]);
      cout << dist << '\n';
    } else {
      long long int lptr = 0;
      long long int rptr = n - 1 - k;
      long long int dist = 0;
      long long int negative = -1;
      long long int positive = -1;
      for (long long int i = 0; i < n; i++) {
        if (arr[i] < 0) {
          negative = i;
        }
      }
      for (long long int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
          positive = i;
        }
      }
      while (lptr <= negative) {
        dist += (abs(arr[lptr]) * 2);
        lptr += k;
      }
      while (rptr >= positive) {
        dist += (arr[rptr] * 2);
        rptr -= k;
      }
      dist += abs(arr[n - 1]);
      cout << dist << '\n';
    }
  }
}
