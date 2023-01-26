#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<int> a(n), hash(n + 1, 0);
  unordered_map<int, int> val;
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<int> b = a;
  b.push_back(INT_MAX);
  int ans = 0;
  sort((b).begin(), (b).end());
  for (long long i = 0; i < n; i++) {
    int pos = 0;
    for (int j = 0; j <= n; j++) {
      if (b[j] > a[i]) {
        pos = j - 1;
        break;
      }
    }
    if (val[a[i]]) {
      ans += val[a[i]];
    } else {
      int x = 0;
      for (int k = 0; k < pos; k++) {
        if (hash[k] == 1) x++;
      }
      ans += x;
      hash[pos] = 1;
      val[a[i]] = x;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
