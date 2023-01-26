#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
pair<int, int> ds[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
long long int _pow(long long int x, long long int n) {
  if (n) {
    long long int u = _pow(x, n / 2);
    u *= u;
    if (n % 2) u *= x;
    return u;
  }
  return 1;
}
long long int mpow(long long int x, long long int n, long long int m) {
  if (n) {
    long long int u = mpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2) u = (u * x) % m;
    return u;
  }
  return 1 % m;
}
int invmod(int a, int m) { return mpow(a, m - 2, m); }
long long int C(int n, int r) {
  if (n < 0) n *= -1;
  if (r < 0) r *= -1;
  long long int ans = 1;
  for (int i = (1); i < (r + 1); i++) {
    ans *= (n + 1 - i);
    ans /= i;
  }
  return ans;
}
long long int mull(long long int a, long long int b, long long int m) {
  return (a % m * b % m) % m;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (auto &i : a) cin >> i;
  set<pair<int, int> > second, t;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++)
      if (a[i][j] == '*') second.insert({i, j});
  }
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      if (a[i][j] == '*') {
        vector<pair<int, int> > te;
        pair<int, int> l = {i - 1, j - 1};
        pair<int, int> r = {i - 1, j + 1};
        int x = 0;
        while (l.first >= 0 and l.second >= 0 and r.second < m) {
          if (a[l.first][l.second] == '*' and
              a[r.first][r.second] == a[l.first][l.second]) {
            te.push_back(l);
            te.push_back(r);
            l.first = r.first = l.first - 1;
            l.second--;
            r.second++;
            x++;
          } else
            break;
        }
        if (x >= k) {
          te.push_back({i, j});
          for (auto &i : te) t.insert(i);
        }
      }
    }
  }
  for (auto &i : t) second.erase(i);
  cout << ((int)second.size() ? "NO" : "YES") << '\n';
}
int main() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
