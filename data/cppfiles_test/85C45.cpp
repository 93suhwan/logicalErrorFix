#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  long long N;
  long long i;
  string s1, s2;
  cin >> s1;
  N = s1.size();
  vector<long long> v(N);
  for (i = 0; i < N; i++) {
    v[i] = s1[i] - '0';
  }
  long long prev = -1;
  long long ans = 0;
  for (i = 0; i < N; i++) {
    if (v[i])
      prev = 1;
    else {
      if (prev == 0)
        continue;
      else
        prev = 0, ans++;
    }
  }
  cout << min(2LL, ans) << '\n';
}
void init() {}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    init();
    solve();
  }
}
