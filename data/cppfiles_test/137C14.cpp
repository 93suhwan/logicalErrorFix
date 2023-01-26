#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, mod = 1e9 + 7;
const long long ll_lim = 1e18 + 7;
const long long int_lim = 1e9 + 7;
int tc;
long long x, y;
unordered_map<string, bool> f;
bool maximize(long long& x, long long y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
bool minimize(long long& x, long long y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> y;
  string S = "", T = "";
  if (x == y) {
    cout << "YES";
    return 0;
  }
  while (x > 0) {
    if (x % 2 == 0)
      S = "0" + S;
    else
      S = "1" + S;
    x /= 2ll;
  }
  while (S[0] == '0') S.erase(0, 1);
  while (y > 0) {
    if (y % 2 == 0)
      T = "0" + T;
    else
      T = "1" + T;
    y /= 2ll;
  }
  while (T[0] == '0') T.erase(0, 1);
  queue<string> q;
  q.push(S);
  while (q.size()) {
    string u = q.front();
    q.pop();
    string s1, s2;
    s1 = u;
    reverse(s1.begin(), s1.end());
    while (s1[0] == '0') s1.erase(0, 1);
    s2 = u + "1";
    reverse(s2.begin(), s2.end());
    while (s2[0] == '0') s2.erase(0, 1);
    if (s1 == T || s2 == T) {
      cout << "YES";
      return 0;
    }
    if (!f[s1] && s1.size() <= T.size()) {
      f[s1] = 1;
      q.push(s1);
    }
    if (!f[s2] && s2.size() <= T.size()) {
      f[s2] = 1;
      q.push(s2);
    }
  }
  cout << "NO";
}
