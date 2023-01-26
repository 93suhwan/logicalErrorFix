#include <bits/stdc++.h>
using namespace std;
void abc() { cout << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cout << a << ' ', abc(b...);
}
template <typename T>
void printv(T l, T r) {
  for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
template <typename T>
ostream& operator<<(ostream& o, vector<T> a) {
  bool is = false;
  if (a.empty()) return o << "{}";
  for (T i : a) {
    o << (is ? ' ' : '{'), is = true, o << i;
  }
  return o << '}';
}
template <typename T>
struct vv : vector<vector<T>> {
  vv(int n, int m, T v) : vector<vector<T>>(n, vector<T>(m, v)) {}
  vv() {}
};
template <typename T>
struct vvv : vector<vv<T>> {
  vvv(int n, int m, int k, T v) : vector<vv<T>>(n, vv<T>(m, k, v)) {}
  vvv() {}
};
const int mod = 998244353, N = 100001, logN = 18, K = 1 << 9, G = 3;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), l(n), r(n);
    long long int sum_all = 0;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i], sum_all += a[i] + b[i] - m;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= m) {
        l[i] = a[i] - m;
      } else {
        l[i] = 0;
      }
      if (b[i] >= m) {
        r[i] = a[i];
      } else {
        r[i] = a[i] + b[i] - m;
      }
    }
    long long int optimal = sum_all >> 1;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = l[i];
      optimal -= l[i], r[i] -= l[i], l[i] = 0;
    }
    for (int i = 0; i < n && optimal > 0; ++i) {
      int mn = min(optimal, 1ll * r[i]);
      optimal -= mn, ans[i] += mn;
    }
    cout << abs(sum_all - accumulate(ans.begin(), ans.end(), 0ll) * 2) << endl;
    for (int i = 0; i < n; ++i) {
      cout << a[i] - ans[i] << ' ' << m - (a[i] - ans[i]) << endl;
    }
  }
}
