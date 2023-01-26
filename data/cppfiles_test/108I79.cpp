#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2,bmi,bmi2,lzcnt,popcnt")
template <typename... T>
void dbg(const char *s, T... args) {
  int cnt = sizeof...(T);
  cerr << "\e[1;32m(" << s << ") = (";
  ((cerr << args << (--cnt ? ", " : ")\e[0m\n")), ...);
}
template <typename T>
void org(const char *s, T L, T R) {
  cerr << "\e[1;32m[ " << s << " ] = [ ";
  while (L != R || (cerr << " ]\e[0m\n", 0))
    cerr << (*L) << (++L != R ? ", " : "");
}
const int maxn = 1e5 + 5;
pair<int, int> pa[maxn];
int surmax[maxn];
bool ans[maxn];
void solve() {
  map<int, int> ma;
  int n;
  cin >> n;
  fill(surmax, surmax + 2 + n, 0);
  fill(ans, ans + 2 + n, 0);
  for (int i = 1; i <= n; i++) cin >> pa[i].first;
  for (int i = 1; i <= n; i++) {
    cin >> pa[i].second;
    ma[pa[i].second] = i;
  }
  sort(pa + 1, pa + 1 + n);
  int premax = 0;
  for (int i = n; i; i--) surmax[i] = max(pa[i].second, surmax[i + 1]);
  for (int i = 1; i <= n; i++) {
    premax = max(premax, pa[i].second);
    if (pa[n].second < premax) ans[ma[pa[i].second]] = 1;
  }
  ans[n] = 1;
  for (int i = 1; i <= n; i++) cout << ans[i];
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
