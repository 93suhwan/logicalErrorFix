#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int pos = 0, num = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    num += s[i] - '0';
    if (s[i] != '0' && i != n - 1) cnt++;
  }
  printf("%d\n", num + cnt);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
