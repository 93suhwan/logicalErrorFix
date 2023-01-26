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
void solve() {
  cin >> s + 1;
  int a = 0, b = 0, n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a = a * 10 + s[i++] - '0';
  for (int i = 2; i <= n; i++) b = b * 10 + s[i++] - '0';
  cout << (a + 1) * (b + 1) - 2 << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
