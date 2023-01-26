#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 1e6 + 5;
int n, m;
string s, q;
bool check() {
  int res = -1;
  for (int i = 0; i <= s.size() - 1; ++i)
    if (s[i] == 'X') {
      if (res == -1)
        res = q[i];
      else {
        if (res != q[i]) return false;
      }
    } else {
      if (s[i] >= '0' && s[i] <= '9' && s[i] != q[i]) return false;
    }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  if (n == 1) {
    if (s[0] != '0')
      cout << 0;
    else
      cout << 1;
    return 0;
  }
  int k = 1;
  for (int i = 1; i <= n - 1; ++i) k *= 10;
  if (n == 2) k = 25;
  int ans = 0;
  for (int i = k; i < k * 10; i += 25) {
    q = to_string(i);
    if (q.size() != s.size()) break;
    if (check()) ans++;
  }
  cout << ans;
}
