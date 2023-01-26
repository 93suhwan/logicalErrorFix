#include <bits/stdc++.h>
using namespace std;
const double E_num = 0.57721566490153286060651209;
const int maxn = 200000 + 10;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
char s[15];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    cin >> s + 1;
    int n = strlen(s + 1);
    int cnt1 = 0, cnt2 = 0;
    int num1 = 0, num2 = 0;
    int ans = n;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '1' && i % 2)
        cnt1++;
      else if (s[i] == '1' && i % 2 == 0)
        cnt2++;
      else if (s[i] == '?' && i % 2)
        num1++;
      else if (s[i] == '?' && i % 2 == 0)
        num2++;
      if (cnt1 + num1 > cnt2 + (10 - i + 1) / 2) {
        ans = i;
        break;
      }
      if (cnt2 + num2 > cnt1 + (10 - i) / 2) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
