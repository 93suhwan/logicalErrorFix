#include <bits/stdc++.h>
using namespace std;
const int N = 66;
bool solve() {
  char str[N];
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  cout << str + 1 << '\n';
  int a[N];
  for (int i = 1; i <= 26; i++) a[i] = 0;
  int cnta = 0, cntb = 0;
  for (int i = 1; i <= len; i++) {
    a[str[i] - 'a' + 1]++;
  }
  int ans = 0;
  sort(a + 1, a + 27);
  for (int i = 26; i >= 1; i--) {
    if (a[i] >= 2)
      ans++;
    else if (a[i] == 1) {
      if (i - 1 >= 0 && a[i - 1] == 1) {
        ans++, i--;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
