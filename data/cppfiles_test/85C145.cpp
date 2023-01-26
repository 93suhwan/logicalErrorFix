#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
char s[N];
int main() {
  int _;
  cin >> _;
  while (_--) {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int ans = 0, f = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0' && s[i - 1] != '0') ans++;
    }
    if (ans > 2) ans = 2;
    cout << ans << endl;
  }
  return 0;
}
