#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vb = vector<bool>;
const string yes = "YES\n", no = "NO\n";
const int maxn = 4e4 + 7;
template <typename A, typename B>
inline bool amin(A &X, B Y) {
  if (Y >= X) return 0;
  X = Y;
  return 1;
}
template <typename A, typename B>
inline bool amax(A &X, B Y) {
  if (Y <= X) return 0;
  X = Y;
  return 1;
}
bool sol(ll a, ll b) {
  vector<bool> x, y, z;
  int c, d;
  while (a > 0) {
    x.push_back(a % 2);
    a /= 2;
  }
  while (b > 0) {
    y.push_back(b % 2);
    b /= 2;
  }
  c = x.size();
  d = y.size();
  for (int i = 0; i < d; ++i) {
    bool ok = 1;
    if (i + c > d) break;
    for (int j = 0; j < c; ++j)
      if (x[j] != y[j + i]) ok = 0;
    if (ok) {
      bool check = 1;
      for (int j = 0; j < i; ++j)
        if (y[j] == 0) check = 0;
      for (int j = i + c; j < d; ++j)
        if (y[j] == 0) check = 0;
      if (check) return 1;
    }
  }
  for (int i = c - 1; i >= 0; --i) z.push_back(x[i]);
  x = z;
  for (int i = 0; i < d; ++i) {
    bool ok = 1;
    if (i + c > d) break;
    for (int j = 0; j < c; ++j)
      if (x[j] != y[j + i]) ok = 0;
    if (ok) {
      bool check = 1;
      for (int j = 0; j < i; ++j)
        if (y[j] == 0) check = 0;
      for (int j = i + c; j < d; ++j)
        if (y[j] == 0) check = 0;
      if (check) return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << yes;
    return 0;
  }
  if (b % 2 == 0) {
    cout << no;
    return 0;
  }
  if (sol(a, b)) {
    cout << yes;
    return 0;
  }
  while (a % 2 == 0) {
    a /= 2;
  }
  if (sol(a, b)) {
    cout << yes;
    return 0;
  }
  cout << no;
  return 0;
}
