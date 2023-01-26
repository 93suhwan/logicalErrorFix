#include <bits/stdc++.h>
using namespace std;
constexpr long long INF_LL = 2000000000000000000LL;
constexpr int INF = 1000000000;
constexpr long long MOD = 998244353;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
long long modpow(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long t = modpow(a, b / 2, m);
  if (b & 1) {
    return (t * t % m) * a % m;
  } else {
    return t * t % m;
  }
}
template <class T>
T gcd(T m, T n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
struct edge {
  int to;
  long long cost;
  edge(int t, long long c) { to = t, cost = c; }
};
void solve() {
  double kk = 400000;
  int n, k;
  cin >> n >> k;
  vector<double> x(n), y(n);
  int idx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[idx] >> y[idx];
    if (x[idx] == 0 && y[idx] == 0) {
      x.pop_back();
      y.pop_back();
      k--;
      continue;
    }
    double tmp = x[idx];
    x[idx] = kk * x[idx] / (x[idx] * x[idx] + y[idx] * y[idx]);
    y[idx] = kk * y[idx] / (tmp * tmp + y[idx] * y[idx]);
    idx++;
  }
  if (k <= 0) {
    cout << 0 << endl;
    return;
  }
  n = x.size();
  double l = 0, r = kk * 2 + 10;
  for (int _ = 0; _ < 50; _++) {
    double m = (r + l) / 2;
    vector<pair<double, int>> li;
    set<int> st;
    for (int i = 0; i < n; i++) {
      double d = x[i] * x[i] + y[i] * y[i] - m * m;
      if (d < 1e-9) continue;
      double t1 =
          atan2(m * (y[i] * m + x[i] * sqrt(d)) / (x[i] * x[i] + y[i] * y[i]),
                m * (x[i] * m - y[i] * sqrt(d)) / (x[i] * x[i] + y[i] * y[i]));
      double t2 =
          atan2(m * (y[i] * m - x[i] * sqrt(d)) / (x[i] * x[i] + y[i] * y[i]),
                m * (x[i] * m + y[i] * sqrt(d)) / (x[i] * x[i] + y[i] * y[i]));
      li.push_back({t1, i + n});
      li.push_back({t2, i});
      if (t1 + 1e-9 < t2) st.insert(i);
    }
    sort(li.begin(), li.end());
    int ma = st.size();
    for (auto &[p, i] : li) {
      if (i >= n) {
        st.erase(i - n);
      } else {
        st.insert(i);
        chmax(ma, (int)st.size());
      }
    }
    if (ma >= k) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << kk / (l * 2) << endl;
}
int main() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(16);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
