#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long change0(long long a) {
  string s;
  while (a) {
    char ch = a % 2 + '0';
    s += ch;
    a /= 2;
  }
  s = '0' + s;
  long long ans = 0;
  string ss;
  long long idx = 0;
  while (s[idx] == '0') idx++;
  for (long long i = idx; i < s.size(); i++) {
    ans *= 2;
    ans += (s[i] - '0');
  }
  return ans;
}
long long change1(long long a) {
  string s;
  while (a) {
    char ch = a % 2 + '0';
    s += ch;
    a /= 2;
  }
  s = '1' + s;
  long long ans = 0;
  string ss;
  long long idx = 0;
  while (s[idx] == '0') idx++;
  for (long long i = idx; i < s.size(); i++) {
    ans *= 2;
    ans += (s[i] - '0');
  }
  return ans;
}
string ca(long long a) {
  string s;
  while (a) {
    char ch = a % 2 + '0';
    s += ch;
    a /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  set<long long> s;
  if (x == y) {
    cout << "YES" << '\n';
    return;
  }
  s.insert(x);
  for (long long i = 1; i <= 100; i++) {
    vector<long long> a;
    for (auto k : s) {
      long long aa = change0(k);
      long long bb = change1(k);
      if (aa == y || bb == y) {
        cout << "YES" << '\n';
        return;
      }
      if (aa >= 0) a.push_back(aa);
      if (bb >= 0) a.push_back(bb);
    }
    for (auto k : a) {
      s.insert(k);
    }
  }
  cout << "NO" << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
