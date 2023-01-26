#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
inline int read() {
  int ans = 0;
  char last = ' ', ch = getchar();
  while (ch<'0' | ch> '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
int n;
int a[maxn];
map<int, int> ma1, ma2;
void solve() {
  n = read();
  int mn = 0x3f3f3f3f;
  ma1.clear(), ma2.clear();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] < 0) a[i] = -a[i];
    ma1[a[i]]++;
  }
  bool ok = 0;
  if (n == 1 && a[1] == 0) ok = 1;
  for (auto it : ma1) {
    if (it.second >= 2) ok = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (++ma2[abs(a[i] - a[j])] >= 2) ok = 1;
    }
  if (ok)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int _t;
  _t = read();
  while (_t--) solve();
  return 0;
}
