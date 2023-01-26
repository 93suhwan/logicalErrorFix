#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long M = (long long)2e18;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
void solve() {
  int n = read(), q = read();
  string s;
  cin >> s;
  vector<vector<int>> num(2, vector<int>(1, 0));
  for (int i = 1; i <= n; i++) {
    num[i % 2].push_back(s[i - 1] == '+' ? 1 : -1);
    num[!(i % 2)].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    num[1][i] = num[1][i - 1] + num[1][i];
    num[0][i] = num[0][i - 1] + num[0][i];
  }
  while (q--) {
    int l = read(), r = read();
    if ((r - l + 1) % 2 == 1)
      cout << 1 << endl;
    else
      cout << min(2,
                  abs(num[1][r] - num[1][l - 1] - (num[0][r] - num[0][l - 1])))
           << endl;
  }
}
signed main() {
  int t = read();
  while (t--) {
    solve();
  }
}
