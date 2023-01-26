#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10, maxm = 1e6 + 10, mod = 998244353;
const double pi = acos(-1), eps = 1e-7;
int T;
int n, k;
set<char> se;
int cnt(string s) {
  set<char> ses;
  for (char i : s) {
    ses.insert(i);
  }
  return ses.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    string s = to_string(n);
    se.clear();
    int m = s.size();
    if (cnt(s) <= k) {
      cout << n << "\n";
    } else {
      if (k == 1) {
        for (char i = s[0]; i <= '9'; i++) {
          string str = "";
          for (int j = 0; j < m; j++) {
            str += i;
          }
          if (str >= s) {
            cout << str << "\n";
            break;
          }
        }
      } else {
        string ans = "9999999999";
        for (int i = (m - 1); i >= 0; i--) {
          se.clear();
          string tem = "";
          for (int j = 0; j < i; j++) {
            se.insert(s[j]);
            tem += s[j];
          }
          int t = se.size();
          if (t > k) continue;
          for (char j = s[i] + 1, cur; j <= '9'; j++) {
            if (se.count(j))
              cur = t;
            else
              cur = t + 1;
            if (cur > k) continue;
            char minv;
            if (cur + 1 <= k)
              minv = '0';
            else
              minv = min(j, *se.begin());
            string res = tem;
            res += j;
            for (int k = i + 1; k < m; k++) {
              res += minv;
            }
            ans = min(ans, res);
          }
        }
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
