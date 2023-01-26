#include <bits/stdc++.h>
using namespace std;
template <typename M, typename N>
istream& operator>>(istream& is, pair<M, N>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename M>
istream& operator>>(istream& is, vector<M>& v) {
  for (auto& it : v) is >> it;
  return is;
}
template <typename M>
istream& operator>>(istream& is, vector<vector<M>>& v) {
  for (auto& it : v) is >> it;
  return is;
}
template <typename M, typename N>
ostream& operator<<(ostream& os, const pair<M, N>& p) {
  os << p.first << ' ' << p.second << '\n';
  return os;
}
template <typename M>
ostream& operator<<(ostream& os, const vector<M>& v) {
  for (auto it : v) os << it << ' ';
  cout << '\n';
  return os;
}
template <typename M>
ostream& operator<<(ostream& os, const vector<vector<M>>& v) {
  for (auto it : v) os << it;
  return os;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int a, int b) { return rng() % (b - a + 1) + a; }
const long double eps = 1e-7;
const long double pi = acos(-1);
const long long inf = (long long)1e9 + 10;
const int mod = 998244353;
int n, m, k;
const int N = 6e5 + 20;
struct fenwicktree {
  vector<long long int> bit;
  int n;
  template <typename M>
  fenwicktree(M size) {
    n = size + 10;
    bit.resize(n);
  }
  template <typename M>
  fenwicktree(vector<M>& a) {
    n = (int)a.size() + 1;
    bit.resize(n);
    for (int i = 0; i < n - 1; i++) {
      add(i, a[i]);
    }
  }
  long long int query(int j) {
    long long int ans = 0;
    for (++j; j; j -= j & -j) {
      ans += bit[j];
    }
    return ans;
  }
  long long int query(int i, int j) { return query(j) - query(i - 1); }
  void add(int id, int val) {
    for (++id; id < n; id += id & -id) {
      bit[id] += val;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  fenwicktree sum(N), no(N), multiples(N);
  vector<long long> ans(n + 1);
  long long u;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    ans[i] += no.query(0, N) * u - multiples.query(0, (int)u);
    for (int j = (int)u; j < N; j += u) {
      if (u != 1) {
        ans[i] += sum.query(j - (int)u + 1, j - 1) -
                  no.query(j - (int)u + 1, j - 1) * (long long)(j - u);
      }
      multiples.add(j, (int)u);
    }
    sum.add((int)u, (int)u);
    no.add((int)u, (int)1);
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
