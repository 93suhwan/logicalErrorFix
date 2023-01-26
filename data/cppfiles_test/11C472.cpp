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
bool sec(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<1>(a) - get<2>(a) > get<1>(b) - get<2>(b);
}
void solve() {
  int n;
  cin >> n;
  map<string, int> m;
  for (int i = (0); i < (n); i++) {
    string second;
    cin >> second;
    m[second]++;
  }
  int ans = 0;
  vector<tuple<int, int, int>> a((int)m.size());
  for (int i = (0); i < (5); i++) {
    int temp = 0;
    for (auto &k : m) {
      int t = 0;
      for (int j = (0); j < ((int)k.first.size()); j++)
        if (k.first[j] == char('a' + i)) t++;
      a[temp++] = {k.second, t, ((int)k.first.size() - t)};
    }
    sort(a.begin(), a.end(), sec);
    int t = 0;
    int r = 0;
    for (int j = (0); j < ((int)a.size()); j++) {
      for (int i = (0); i < (get<0>(a[j])); i++) {
        if (r + get<1>(a[j]) - get<2>(a[j]) > 0) {
          r += get<1>(a[j]) - get<2>(a[j]);
          t++;
        } else
          break;
      }
    }
    ans = max(ans, t);
  }
  cout << ans << '\n';
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
