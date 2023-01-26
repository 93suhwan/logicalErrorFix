#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 20;
const int null = 0x3f3f3f3f, INF = 1e9;
const long long mod = 998244353;
int T;
int n;
int a[N];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int res = 1;
    for (int i = 1; i <= n; i++) cin >> a[i], res *= 3;
    int flag = 0;
    for (int i = 1; i <= res - 1; i++) {
      int t = i, sum = 0;
      for (int i = 1; i <= n; i++) {
        if (t % 3 == 1) sum += a[i];
        if (t % 3 == 2) sum -= a[i];
        t /= 3;
      }
      if (!sum) {
        flag = 1;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
