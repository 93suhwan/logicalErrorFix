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
template <typename T>
struct vvvv : vector<vvv<T>> {
  vvvv(int n, int m, int k, int t, T v)
      : vector<vvv<T>>(n, vvv<T>(m, k, t, v)) {}
  vvvv() {}
};
const int mod = 998244353, N = 300001, logN = 20, K = 450;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  vector<int> pre(m + 1);
  vv<int> cycle(K, K, 0);
  vector<int> in(n, -1);
  int cur = 0;
  for (int i = 0, op, p; i < m; ++i) {
    cin >> op >> p, --p;
    if (op == 1) {
      in[p] = i;
      if (x[p] + y[p] < K) {
        int m = x[p] + y[p];
        for (int j = (i + x[p]) % m, cnt = 0; cnt < y[p];
             ++cnt, j = (j + 1) % m) {
          cycle[m][j]++;
        }
      } else {
        int now = i;
        while (now < m) {
          now += x[p];
          pre[min(now, m)]++;
          now += y[p];
          pre[min(now, m)]--;
        }
      }
    } else {
      if (x[p] + y[p] < K) {
        int m = x[p] + y[p];
        for (int j = (in[p] + x[p]) % m, cnt = 0; cnt < y[p];
             ++cnt, j = (j + 1) % m) {
          cycle[m][j]--;
        }
        in[p] = -1;
      } else {
        int now = in[p];
        in[p] = -1;
        bool is = false;
        while (now < m) {
          if (now + x[p] < i && i <= now + x[p] + y[p]) is = true;
          now += x[p];
          pre[min(now, m)]--;
          now += y[p];
          pre[min(now, m)]++;
        }
        if (is) cur--;
      }
    }
    cur += pre[i];
    int ans = cur;
    for (int j = 1; j < K; ++j) {
      ans += cycle[j][i % j];
    }
    cout << ans << '\n';
  }
}
