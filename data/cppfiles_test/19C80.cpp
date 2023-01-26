#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n, a[20010];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<pair<long long, long long> > memo;
  memo.push_back(make_pair(0, 0));
  long long lim = 2000;
  for (long long i = 1; i <= n; i++) {
    long long d = a[i];
    vector<long long> aux(2000 + 10, 1123456789);
    for (auto it : memo) {
      long long j = it.first, tam = it.second;
      long long esq = j - d, dir = j + d;
      if (esq < 0) {
        if (tam + abs(esq) <= lim) aux[0] = min(aux[0], tam + abs(esq));
      } else {
        aux[esq] = min(aux[esq], tam);
      }
      if (dir > tam and dir <= lim)
        aux[dir] = min(aux[dir], dir);
      else if (dir <= lim)
        aux[dir] = min(aux[dir], tam);
    }
    memo.clear();
    for (long long i = 0; i <= lim; i++)
      if (aux[i] != 1123456789) memo.push_back(make_pair(i, aux[i]));
  }
  long long ans = 1123456789;
  for (auto u : memo) ans = min(ans, u.second);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve();
}
