#include <bits/stdc++.h>
using namespace std;
char str[100010], stt[100010];
void slove() {
  int n, a = 0, b = 0, ans = 0;
  memset(str, '\0', sizeof(str));
  cin >> n;
  memset(stt, '\0', sizeof(stt));
  scanf("%s%s", str, stt);
  for (int i = 0; i < n; ++i) {
    if (str[i] == '1') a++;
    if (stt[i] == '0') b++;
    if (str[i] != stt[i]) ans++;
  }
  if ((a + b == n) || (a - 1 == b)) {
    if (!(ans & 1)) {
      int sum = ans;
      if ((n - ans) & 1) sum = min(sum, n - ans);
      printf("%d\n", sum);
      return;
    } else {
      int sum = 0;
      if ((n - ans) & 1)
        sum = n - ans;
      else {
        cout << "-1\n";
        return;
      }
      printf("%d\n", sum);
      return;
    }
    return;
  }
  cout << "-1\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
  return 0;
}
