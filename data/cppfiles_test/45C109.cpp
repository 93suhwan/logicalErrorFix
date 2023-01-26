#include <bits/stdc++.h>
using namespace std;
bool die(int *arr, int n) {
  int s = n;
  if (s == 1) {
    return false;
  }
  for (int i = 0; i < s - 1; i++) {
    if ((arr[i] == arr[i + 1]) && (arr[i] == 0)) {
      return true;
    }
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    if (die(arr, n)) {
      cout << "-1\n";
    } else {
      int s = 1;
      for (int k = 0; k < n; k++) {
        if ((k != 0) && (arr[k - 1] == arr[k]) && (arr[k] == 1)) {
          s += 5;
        } else if (arr[k] == 1) {
          s += 1;
        } else {
        }
      }
      cout << s << "\n";
    }
  }
  return 0;
}
