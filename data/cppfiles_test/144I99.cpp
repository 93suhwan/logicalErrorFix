#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long bigger_cnt = n % m, small_cnt = m - bigger_cnt;
  long long start = 0;
  for (long long i = 0; i < k; i++) {
    for (long long _ = 0; _ < bigger_cnt; _++) {
      cout << (n + m - 1) / m << " ";
      for (long long __ = 0; __ < (n + m - 1) / m; __++) {
        cout << start + 1 << " ";
        start++;
      }
      cout << "\n";
    }
    long long st = start;
    for (long long _ = 0; _ < small_cnt; _++) {
      cout << n / m << " ";
      for (long long __ = 0; __ < n / m; __++) {
        cout << st + 1 << " ";
        st++;
      }
      cout << "\n";
    }
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio();
  cin.tie(nullptr);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
