#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> pre(n + 1, 0), suff(n + 1, 0);
  long long add = 1;
  for (long long i = 1; i <= n; i++) {
    pre[i] = add;
    add++;
  }
  add = 1;
  for (long long i = n; i >= 1; i--) {
    suff[i] = add;
    add++;
  }
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B') {
      if (arr[i] < 1) {
        cout << "NO" << endl;
        return;
      } else {
        pre[min(arr[i], n)]--;
        if (pre[min(arr[i], n)] < 0) {
          cout << "NO" << endl;
          return;
        }
      }
    } else {
      if (arr[i] > n) {
        cout << "NO" << endl;
        return;
      } else {
        suff[max(arr[i], 1LL)]--;
        if (suff[max(arr[i], 1LL)] < 0) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
