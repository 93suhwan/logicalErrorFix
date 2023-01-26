#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < int(v.size()); ++i) is >> v[i];
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (T x : v) os << x << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> s) {
  for (T x : s) os << x << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> s) {
  for (T x : s) os << x << " ";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> m) {
  for (auto x : m) os << x << " ";
  return os;
}
template <typename T>
T sum(vector<T> v) {
  T summ = 0;
  for (int i = 0; i < int(int(v.size())); ++i) summ += v[i];
  return summ;
}
long long mod_pow(long long a, long long b) {
  long long sol = 1;
  while (b) {
    if (b & 1) {
      sol = (sol * a) % mod;
      b--;
    } else {
      a = (a * a) % mod;
      b /= 2;
    }
  }
  return sol;
}
long long rem(long long a, long long b) {
  long long res = a % b;
  return res < 0 ? res + b : res;
}
void test_case() {
  int n, m;
  cin >> n >> m;
  map<int, int> diff;
  vector<int> v(n);
  cin >> v;
  map<int, int> rep;
  for (int i = 0; i < int(n); ++i) {
    diff[rem(v[i] - i, n)]++;
    rep[rem(v[i] - i, n)] = i;
  }
  set<int> sol;
  for (auto p : diff) {
    if (n - p.second - 1 <= m) {
      sol.insert(rem(rep[p.first] - (v[rep[p.first]] - 1), n));
    }
  }
  cout << int(sol.size()) << " ";
  cout << sol << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < int(t); ++i) test_case();
  return 0;
}
