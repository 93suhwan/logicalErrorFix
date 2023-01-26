#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
bool check(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  bool flag = true;
  int cnt = 0;
  while (1) {
    if (check(arr, n)) break;
    for (int i = ((flag) ? (0) : (1)); i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
    flag = !flag;
    cnt++;
  }
  cout << cnt;
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
