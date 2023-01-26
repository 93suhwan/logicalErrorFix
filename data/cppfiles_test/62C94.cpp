#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream &operator<<(ostream &o, const pair<T, S> &p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream &>::type operator<<(
    ostream &o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
long long int v[2][1010][1010], nm[2 * 1010];
set<long long int> s[2 * 1010];
long long int c2(long long int x) { return x * (x - 1) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  long long int m;
  cin >> m;
  long long int qs;
  cin >> qs;
  for (long long int i = 0; i < (n); ++i)
    for (long long int j = 0; j < (m); ++j) {
      v[0][i][j] = ++nm[i - j + 1010];
      v[1][i][j] = ++nm[i - j + 1 + 1010];
    }
  long long int ans = 0, sq = n * m;
  for (long long int i = 0; i < (2 * 1010); ++i)
    s[i].insert(0), s[i].insert(nm[i] + 1), ans += c2(nm[i]);
  while (qs--) {
    long long int x;
    cin >> x;
    long long int y;
    cin >> y;
    x--;
    y--;
    for (long long int z = 0; z < (2); ++z) {
      long long int k = x - y + z + 1010;
      long long int q = v[z][x][y];
      long long int a = *--s[k].lower_bound(q);
      long long int b = *s[k].upper_bound(q);
      if (s[k].count(q)) {
        ans -= c2(q - a - 1);
        ans -= c2(b - q - 1);
        s[k].erase(q);
        ans += c2(b - a - 1);
      } else {
        ans -= c2(b - a - 1);
        s[k].insert(q);
        ans += c2(q - a - 1);
        ans += c2(b - q - 1);
      }
    }
    if (s[x - y + 1010].count(v[0][x][y]))
      sq--;
    else
      sq++;
    cout << ans + sq << '\n';
  }
}
