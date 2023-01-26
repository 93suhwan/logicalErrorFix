#include <bits/stdc++.h>
using namespace std;
void solve(int z) {
  long long int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int cnt = 1, ans = 0;
  while (true) {
    bool f1 = true;
    if (cnt) {
      for (int i = 1; i <= n - 2; i += 2) {
        if (arr[i] > arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
          f1 = false;
        }
      }
    } else {
      for (int i = 2; i <= n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
          f1 = false;
        }
      }
    }
    if (f1) {
      cout << ans << "\n";
      return;
    }
    cnt = 1 - cnt;
    ans++;
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
