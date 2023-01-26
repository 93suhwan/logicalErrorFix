#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
std::vector<long long> sa(string s1, string s) {
  long long c = 0;
  std::vector<long long> ans;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] != s1[i]) {
      c++;
    }
    ans.push_back(c);
  }
  return ans;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string s1;
  string s2;
  string s3;
  string s4;
  string s5, s6;
  s1 = "";
  s2 = s1;
  s3 = s1;
  char a = 'a';
  for (long long i = 0; i < n; i++) {
    if (a == 'd') {
      a = 'a';
    }
    s1 += a;
    a++;
  }
  a = 'a';
  for (long long i = 0; i < n; i++) {
    s2 += a;
    if (a == 'a') {
      a = 'c';
    } else {
      a--;
    }
  }
  a = 'b';
  for (long long i = 0; i < n; i++) {
    if (a == 'd') {
      a = 'a';
    }
    s3 += a;
    a++;
  }
  a = 'b';
  for (long long i = 0; i < n; i++) {
    s4 += a;
    if (a == 'a') {
      a = 'c';
    } else {
      a--;
    }
  }
  a = 'c';
  for (long long i = 0; i < n; i++) {
    if (a == 'd') {
      a = 'a';
    }
    s5 += a;
    a++;
  }
  a = 'c';
  for (long long i = 0; i < n; i++) {
    s6 += a;
    if (a == 'a') {
      a = 'c';
    } else {
      a--;
    }
  }
  std::vector<std::vector<long long> > v(6, std::vector<long long>(n));
  v[0] = sa(s1, s);
  v[1] = sa(s2, s);
  v[2] = sa(s3, s);
  v[3] = sa(s4, s);
  v[4] = sa(s5, s);
  v[5] = sa(s6, s);
  while (m--) {
    long long ans = INT_MAX;
    long long l, r;
    cin >> l >> r;
    l--, r--;
    for (long long i = 0; i < 6; i++) {
      if (l != 0) {
        ans = min(ans, (v[i][r] - v[i][l - 1]));
      } else
        ans = min(ans, v[i][r]);
    }
    cout << ans << endl;
  }
}
signed main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
