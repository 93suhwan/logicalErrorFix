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
    string hi = s.substr(0, s.size() - 2);
    reverse(hi.begin(), hi.end());
    tmp = s.substr(0, s.size() - 1) + hi;
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] == t[idx]) idx++;
      if (idx = t.size()) {
        flag = 1;
        break;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
