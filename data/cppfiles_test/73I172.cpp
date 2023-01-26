#include <bits/stdc++.h>
using namespace std;
void solve(int z) {
  long long int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int cnt = 1;
  while (true) {
    bool f1 = true, f2 = true;
    if (cnt % 2 != 0) {
      for (int i = 0; i < n; i += 2) {
        if ((i + 1) <= (n - 1) && arr[i] > arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
          f1 = false;
        }
      }
    } else {
      for (int i = 1; i < n; i += 2) {
        if ((i + 1) <= (n - 1) && arr[i] > arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
          f2 = false;
        }
      }
    }
    if (f2 && f1) {
      cout << cnt - 1 << "\n";
      return;
    }
    cnt++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int c = 1;
  while (t--) {
    solve(c);
    c++;
  }
  return 0;
}
