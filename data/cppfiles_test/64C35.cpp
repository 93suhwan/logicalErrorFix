#include <bits/stdc++.h>
using namespace std;
vector<int> z_func(const vector<int>& s) {
  int n = s.size();
  vector<int> z(n, 0);
  z[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int rd_md() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int res = -1;
  while (1) {
    bool pr = 1;
    int md = rng() % (int)1e9;
    for (int i = 2; i * i <= md; ++i) {
      if (md % i == 0) {
        pr = 0;
        break;
      }
    }
    if (pr) {
      res = md;
      break;
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int md = rd_md();
  string s_, x_;
  cin >> s_ >> x_;
  int n = s_.size(), m = x_.size();
  vector<int> s(n), x(m);
  for (int i = 0; i < n; ++i) s[i] = s_[i] - 48;
  int X = 0;
  for (int i = 0; i < m; ++i) {
    X = (X * 10ll + x_[i] - 48) % md;
    x[i] = x_[i] - 48;
  }
  vector<int> h(n), pw(n + 1);
  pw[0] = 1;
  for (int i = 0; i < n; ++i) {
    pw[i + 1] = pw[i] * 10ll % md;
    h[i] = ((i ? h[i - 1] : 0) * 10ll + s[i]) % md;
  }
  auto get = [&](int i, int j) -> int {
    return (h[j] - 1ll * (i ? h[i - 1] : 0) * pw[j - i + 1] + 1ll * md * md) %
           md;
  };
  if (m > 1) {
    for (int i = 0; i + 2 * (m - 1) - 1 < n; ++i) {
      int sum = (get(i, i + m - 2) + get(i + m - 1, i + 2 * (m - 1) - 1)) % md;
      if (sum == X) {
        cout << i + 1 << ' ' << i + m - 1 << '\n';
        cout << i + m << ' ' << i + 2 * (m - 1);
        return 0;
      }
    }
  }
  vector<int> seq(x);
  seq.push_back(-1);
  seq.insert(seq.end(), s.begin(), s.end());
  vector<int> z = z_func(seq);
  for (int i = 0; i + m - 1 < n; ++i) {
    int lcp = z[i + 1 + m];
    for (int j = m - lcp - 1; j <= m - lcp; ++j) {
      if (j < 1) continue;
      if (i + j + m - 1 < n) {
        int sum = (get(i, i + m - 1) + get(i + m, i + j + m - 1)) % md;
        if (sum == X) {
          cout << i + 1 << ' ' << i + m << '\n';
          cout << i + m + 1 << ' ' << i + j + m;
          return 0;
        }
      }
      if (i >= j) {
        int sum = (get(i - j, i - 1) + get(i, i + m - 1)) % md;
        if (sum == X) {
          cout << i - j + 1 << ' ' << i << '\n';
          cout << i + 1 << ' ' << i + m;
          return 0;
        }
      }
    }
  }
  return 0;
}
