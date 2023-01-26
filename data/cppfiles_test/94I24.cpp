#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long M = 1e2 + 5;
const long long mod = 998244353;
const int inf = 1e9;
const double eps = 1e-9;
const double PI = acos(-1.0);
const pair<int, int> NIL = {0, 0};
char s[12];
long long n, ans;
void dfs(int id, long long cur, int add) {
  if (id == 0) {
    ans += cur;
    return;
  }
  if (id < 0) return;
  if (add == 1 && s[id] == '0') {
    if (id - 2 > 0 && s[id - 1] == '0') dfs(id - 2, cur * 18, 1);
  } else {
    dfs(id - 1, cur * (s[id] - '0' + 1 - add), 0);
    if (s[id - 1] == '0' && id > 2) {
      if (s[id] == '0')
        dfs(id - 2, cur * 9, 1);
      else
        dfs(id - 2, cur * (9 - s[id] + '0'), 1);
    }
  }
}
void solve() {
  cin >> s + 1;
  n = strlen(s + 1);
  ans = 0;
  dfs(n, 1, 0);
  cout << ans - 2 << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
