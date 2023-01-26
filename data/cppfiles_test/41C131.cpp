#include <bits/stdc++.h>
#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
#pragma gcc optimize("abm,mmx,avx,avx2,unroll-loops,fast-math,section-anchors")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<long long>> pref;
  auto lol = {'a', 'b', 'c'};
  for (auto& a : lol) {
    for (auto& b : lol) {
      for (auto& c : lol) {
        if (a != b && a != c && b != c) {
          pref.emplace_back(n + 1);
          for (long long i = 0; i < n; i++) {
            char d = (i % 3 == 0 ? a : (i % 3 == 1 ? b : c));
            pref.back()[i + 1] = pref.back()[i] + (s[i] != d);
          }
        }
      }
    }
  }
  while (m--) {
    long long L, R;
    cin >> L >> R;
    --L;
    --R;
    long long ans = (long long)(1e9);
    for (auto& it : pref) ans = min(ans, it[R + 1] - it[L]);
    cout << ans << endl;
  }
}
