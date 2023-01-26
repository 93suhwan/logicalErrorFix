#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> cnt(n);
  long long val = 0;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    v--;
    u--;
    if (u < v) {
      swap(u, v);
    }
    if (!cnt[v]) {
      val++;
    }
    cnt[v]++;
  }
  long long q;
  cin >> q;
  while (q--) {
    long long type;
    cin >> type;
    if (type == 3) {
      cout << n - val << "\n";
    } else if (type == 1) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u < v) {
        swap(u, v);
      }
      if (!cnt[v]) {
        val++;
      }
      cnt[v]++;
    } else {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u < v) {
        swap(u, v);
      }
      if (cnt[v] == 1) {
        val--;
      }
      cnt[v]--;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
