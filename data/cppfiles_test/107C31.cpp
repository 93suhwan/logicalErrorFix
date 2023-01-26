#include <bits/stdc++.h>
using namespace std;
bool fun(int arr[], int n, int a, int b) {
  if (abs(a - b) > 1) return false;
  int j = 1;
  for (int i = 0; i < n; i++) {
    arr[i] = j;
    j++;
  }
  if (a == b) {
    if ((2 * a + 1) + 1 > n) return false;
    int ct = 1;
    for (int i = 0; i < a + 1; i++) {
      arr[2 * i] = ct;
      ct++;
    }
    for (int i = 0; i < a + 1; i++) {
      arr[2 * i + 1] = ct;
      ct++;
    }
    return true;
  }
  if (b > a) {
    int ct = 1;
    if (2 * b + 1 > n) return false;
    for (int i = 0; i < b; i++) {
      arr[2 * i + 1] = ct;
      ct++;
    }
    for (int i = 0; i < b + 1; i++) {
      arr[2 * i] = ct;
      ct++;
    }
    return true;
  }
  if (a > b) {
    int ct = n - 2 * a;
    if (2 * a + 1 > n) return false;
    for (int i = 0; i < a + 1; i++) {
      arr[2 * i + n - 2 * a - 1] = ct;
      ct++;
    }
    for (int i = 0; i < a; i++) {
      arr[2 * i + 1 + n - 2 * a - 1] = ct;
      ct++;
    }
    return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n];
    if (!fun(arr, n, a, b))
      cout << -1 << "\n";
    else {
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
