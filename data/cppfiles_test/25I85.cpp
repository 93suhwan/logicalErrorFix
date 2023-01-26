#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int n;
  cin >> n;
  while (n--) {
    string s, tmp, t;
    cin >> s >> t;
    int flag = 0, idx = 0, ans = 0;
    string s2 = s;
    s.erase(s.size() - 1, 1);
    reverse(s2.begin(), s2.end());
    s += s2;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == t[idx]) idx++;
      if (idx = t.size()) {
        flag = 1;
        break;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
