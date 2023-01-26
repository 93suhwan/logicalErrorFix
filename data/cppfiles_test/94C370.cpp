#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
void solve() {
  string s;
  cin >> s;
  int f = 1;
  int n = s.size();
  long long a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      a = a * 10 + s[i] - '0';
    else
      b = b * 10 + s[i] - '0';
  }
  a++, b++;
  cout << a * b - 2 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
