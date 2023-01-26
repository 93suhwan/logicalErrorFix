#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int T, n;
char s[N];
void solve() {
  scanf("%d%s", &n, s + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?') cnt++;
  }
  while (cnt) {
    for (int i = 1; i <= n; i++)
      if (s[i] == '?' && s[i + 1] != '?') {
        if (s[i + 1] == 'B') {
          s[i] = 'R';
          cnt--;
        } else {
          s[i] = 'B';
          cnt--;
        }
      }
  }
  printf("%s\n", s + 1);
}
int main() {
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
