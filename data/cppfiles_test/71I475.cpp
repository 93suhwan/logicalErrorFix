#include <bits/stdc++.h>
using namespace std;
bool works(string s, char c) {
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] > c) return false;
    if (s[i] < c) return true;
  }
  return true;
}
void recur(string &s, string &res, string cur, char &a, char &b) {
  if (cur.size() == s.size()) {
    if (cur[0] == 0) return;
    if (stoi(cur) < stoi(s)) return;
    if (res.size() == 0)
      res = cur;
    else if (stoi(cur) < stoi(res))
      res = cur;
    return;
  }
  recur(s, res, cur + a, a, b);
  recur(s, res, cur + b, a, b);
}
string getComb(string s, char a, char b) {
  string res = "";
  recur(s, res, "", a, b);
  b++;
  if (res.size() == 0) recur(s, res, "", a, b);
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
      else
        cout << getComb(s, a, b);
    }
    cout << '\n';
  }
  return 0;
}
