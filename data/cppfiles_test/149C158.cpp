#include <bits/stdc++.h>
using namespace std;
inline void debugMode() {}
void solvecases(int cse) {
  int n, k;
  long long x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long> d;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*')
      ++cnt;
    else {
      if (cnt) {
        d.push_back(cnt);
        cnt = 0;
      }
    }
  }
  if (cnt) d.push_back(cnt);
  if (d.empty()) {
    cout << s << '\n';
    return;
  }
  if (k == 0) {
    for (auto e : s) {
      if (e == 'a') cout << 'a';
    }
    cout << '\n';
    return;
  }
  for (auto &e : d) {
    e = e * k + 1;
  }
  vector<long long> ans((int)d.size(), 0);
  vector<long long> m((int)d.size() + 1);
  for (int i = 0; i < (int)d.size(); ++i) m[i] = LLONG_MAX;
  m[(int)d.size()] = 1;
  for (int i = (int)d.size() - 1; i >= 0; --i) {
    if (log10((long double)d[i]) + log10((long double)m[i + 1]) > 18.0) break;
    m[i] = m[i + 1] * d[i];
  }
  --x;
  for (int i = 1; i < (int)d.size(); ++i) {
    if (m[i] != LLONG_MAX && m[i] <= x) {
      ans[i - 1] = x / m[i];
      x %= m[i];
    }
  }
  ans[(int)d.size() - 1] = x;
  int i = 0, j = 0;
  string b;
  while (i < n) {
    if (s[i] == '*') {
      for (int kk = 0; kk < ans[j]; ++kk) b += 'b';
      ++j;
      while (i < n && s[i] == '*') {
        ++i;
      }
    } else {
      b += 'a';
      ++i;
    }
  }
  cout << b << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solvecases(i);
  }
}
