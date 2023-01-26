#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int maxs = 500010;
int t;
long long n, ans, vis[maxs];
string s1, s2;
int main() {
  cin >> t;
  while (t--) {
    n = read();
    for (int i = 0; i <= n; i++) vis[i] = 0;
    ans = 0;
    cin >> s1 >> s2;
    for (int i = 0; i <= n - 1; i++) {
      if (s1[i] == '0' && s2[i] == '1' && vis[i] == 0) {
        ++ans;
        s2[i] = '0';
        vis[i] = 1;
      }
      if (i > 0 && s1[i] == '1' && s2[i - 1] == '1' && vis[i] == 0) {
        ++ans;
        vis[i] = 1;
        s2[i - 1] = '0';
      }
      if (i < n - 1 && s1[i] == '1' && s2[i + 1] == '1' && vis[i] == 0) {
        ++ans;
        vis[i] = 1;
        s2[i + 1] = '0';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
