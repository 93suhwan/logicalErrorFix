#include <bits/stdc++.h>
using namespace std;
const long long int N = 20005;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
long long int solve() {
  long long int n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long int> p;
  long long int cur = 0;
  string nev;
  for (long long int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      if (cur) nev.push_back('*');
      nev.push_back('a');
      if (cur) p.push_back(cur);
      cur = 0;
    } else {
      cur++;
    }
  }
  if (cur) nev.push_back('*');
  if (cur) p.push_back(cur);
  long long int sz = p.size();
  vector<long long int> ans(sz, 0);
  long long int pw = 1;
  long long int idx = sz - 1;
  x--;
  while (x) {
    cur = k * p[idx] + 1;
    ans[idx] = x % cur;
    x /= cur;
    idx--;
  }
  string y;
  long long int j = 0;
  for (long long int i = 0; i < nev.size(); ++i) {
    if (nev[i] == 'a')
      y.push_back('a');
    else {
      long long int m = ans[j];
      for (long long int l = 0; l < m; ++l) y.push_back('b');
      j++;
    }
  }
  return cout << y << "\n", 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
