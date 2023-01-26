#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n + 10];
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  long long int cnt = 0;
  if (n == 1) {
    cout << 1 << "\n";
    return;
  } else if (n == 2) {
    cout << 3 << "\n";
    return;
  }
  long long int temp = 0;
  for (long long int i = 0; i <= n - 4; i++) {
    long long int a = arr[i];
    long long int b = arr[i + 1];
    long long int c = arr[i + 2];
    long long int d = arr[i + 3];
    if (!(((a <= b && b <= c) || (a <= b && b <= d) || (a <= c && c <= d) ||
           (b <= c && c <= d)) ||
          ((a >= b && b >= c) || (a >= b && b >= d) || (a >= c && c >= d) ||
           (b >= c && c >= d)))) {
      cnt++;
    }
    if (!((a <= b && b <= c) || ((a >= b && b >= c)))) {
      cnt++;
    }
  }
  long long int i = n - 3;
  long long int a = arr[i];
  long long int b = arr[i + 1];
  long long int c = arr[i + 2];
  if (!((a <= b && b <= c) || ((a >= b && b >= c)))) {
    cnt++;
  }
  cnt += n - 1;
  cout << cnt << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t;
  cin >> _t;
  while (_t--) solve();
}
