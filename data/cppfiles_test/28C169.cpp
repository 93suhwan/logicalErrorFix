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
  vector<int> v(n);
  for (int i = 0; i < int(n); ++i) {
    cin >> v[i];
    v[i]--;
  }
  vector<pair<int, int> > ks;
  for (int i = 0; i < int(n); ++i) {
    ks.push_back({0, i});
  }
  for (int i = 0; i < int(n); ++i) {
    ks[rem(i - v[i], n)].first++;
  }
  set<int> sol;
  for (int i = 0; i < int(n); ++i) {
    if (ks[i].first < n / 3) continue;
    vector<int> perm;
    for (int j = (n - ks[i].second) % n; j < int((n - ks[i].second) % n + n);
         ++j) {
      perm.push_back(j % n);
    }
    map<int, int> g;
    for (int j = 0; j < int(n); ++j) {
      g[v[j]] = perm[j];
    }
    int k = 0;
    set<int> vis;
    for (int j = 0; j < int(n); ++j) {
      if (vis.count(j) > 0) continue;
      int from = j;
      while (!vis.count(from)) {
        vis.insert(from);
        from = g[from];
      }
      k++;
    }
    if (n - k <= m) {
      sol.insert(ks[i].second);
    }
  }
  cout << int(sol.size()) << " " << sol << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < int(t); ++i) test_case();
  return 0;
}
