#include <bits/stdc++.h>
using namespace std;
bool works(string s, char c) {
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] > c) return false;
    if (s[i] < c) return true;
  }
  return true;
}
void recur(string &s, string &res, string &cur, char a, char b) {
  if (cur.size() == s.size()) {
    if (cur[0] == 0) return;
    if (cur < s) return;
    if (res.size() == 0)
      res = cur;
    else if (cur < res)
      res = cur;
    return;
  }
  cur += a;
  recur(s, res, cur, a, b);
  cur.pop_back();
  cur += b;
  recur(s, res, cur, a, b);
  cur.pop_back();
}
string getComb(string s, string res, char a, char b) {
  string cur = "";
  recur(s, res, cur, a, b);
  if (b == '9') return res;
  b++;
  recur(s, res, cur, a, b);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    string s = to_string(n);
    if (k == 1) {
      if (works(s, s[0]))
        cout << string(s.size(), s[0]);
      else
        cout << string(s.size(), s[0] + 1);
    } else {
      char a = s[0];
      char b = '*';
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] != a) {
          b = s[i];
          break;
        }
      }
      if (b == '*')
        cout << string(s.size(), a);
      else {
        string res = string(s.size(), s[0] + 1);
        bool found = false;
        string x = "", y = "", z = "";
        for (long long i = 0; i < s.size(); i++) {
          if (s[i] != a) {
            if (s[i] < a) {
              x += a;
              x += string(s.size() - i - 1, '0');
            }
            recur(s, res, y, a, s[i]);
            if (s[i] != '9') recur(s, res, z, a, s[i] + 1);
            if (x.size() == s.size() && x >= s) res = min(res, x);
            if (y.size() == s.size() && y >= s) res = min(res, y);
            if (z.size() == s.size() && z >= s) res = min(res, z);
            break;
          } else
            x += s[i];
        }
        cout << res;
      }
    }
    cout << '\n';
  }
  return 0;
}
