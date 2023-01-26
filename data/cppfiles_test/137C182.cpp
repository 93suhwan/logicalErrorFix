#include <bits/stdc++.h>
using namespace std;
string g(long long n) {
  string ans = "";
  while (n) {
    long long bi = n & 1;
    if (bi)
      ans += "1";
    else
      ans += "0";
    n >>= 1;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
bool check(string s1, string s2) {
  auto it = s2.find(s1);
  if (it == string::npos) return false;
  for (long long i = 0; i < it; i++) {
    if (s2[i] == '0') return false;
  }
  for (long long i = it + s1.size(); i < s2.size(); i++) {
    if (s2[i] == '0') return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x == y) {
      cout << "YES\n";
      continue;
    }
    string s1 = g(x);
    string s2 = g(y);
    if (s1[s1.size() - 1] == '1') {
      if (check(s1, s2))
        cout << "YES\n";
      else {
        string s = s1;
        reverse(s.begin(), s.end());
        if (check(s, s2))
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    } else {
      string st = s1;
      s1 += "1";
      if (check(s1, s2)) {
        cout << "YES\n";
        continue;
      } else {
        string s = s1;
        reverse(s.begin(), s.end());
        if (check(s, s2)) {
          cout << "YES\n";
          continue;
        }
      }
      long long x = st.size() - 1;
      while (st[x] != '1') x--;
      string str = "";
      for (long long i = 0; i <= x; i++) str += st[i];
      s1 = str;
      if (check(s1, s2)) {
        cout << "YES\n";
        continue;
      } else {
        string s = s1;
        reverse(s.begin(), s.end());
        if (check(s, s2)) {
          cout << "YES\n";
          continue;
        }
      }
      cout << "NO\n";
    }
  }
  return 0;
}
