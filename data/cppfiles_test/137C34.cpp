#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long x, y, cntx, cnty;
bool ok;
string s, t;
void gets(long long x, string& s) {
  s = "";
  while (x) {
    s += (char)(x % 2 + '0');
    x >>= 1;
  }
  reverse(s.begin(), s.end());
  return;
}
void dfs(string s, int cnt) {
  if (cnt > cnty) return;
  if (s.size() > t.size()) return;
  if (s.size() == t.size()) {
    if (s == t) {
      ok = true;
      return;
    }
    int i, len = s.size();
    for (i = 0; i < len; i++) {
      if (s[i] != t[len - i - 1]) break;
    }
    if (i == len) ok = true;
    if (ok) return;
  }
  bool f = false;
  string ss = "";
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '0') f = true;
    if ((!f) && s[i] == '0') continue;
    ss += s[i];
  }
  if (ss == t) {
    ok = true;
    return;
  }
  reverse(s.begin(), s.end());
  if (cnty - cnt == t.size() - s.size()) dfs("1" + s, cnt + 1);
  if (ok) return;
  cnt = 0;
  for (int i = 0; i < ss.size(); i++)
    if (ss[i] == '1') cnt++;
  reverse(ss.begin(), ss.end());
  if (cnty - cnt == t.size() - ss.size()) dfs("1" + ss, cnt + 1);
  return;
}
int main() {
  cin >> x >> y;
  gets(x, s), gets(y, t);
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') cntx++;
  for (int i = 0; i < t.size(); i++)
    if (t[i] == '1') cnty++;
  dfs(s, cntx);
  if (!ok) {
    bool f = false;
    string ss = "";
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != '0') f = true;
      if ((!f) && s[i] == '0') continue;
      ss += s[i];
    }
    cntx = 0;
    for (int i = 0; i < ss.size(); i++)
      if (ss[i] == '1') cntx++;
    dfs(ss, cntx);
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
