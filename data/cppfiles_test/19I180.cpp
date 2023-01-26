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
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < 0) flag = 1;
    }
    if (n == 1) {
      if (a[1] != 0)
        puts("NO");
      else
        puts("YES");
    } else {
      if (n == 2)
        puts("NO");
      else {
        if (flag)
          puts("YES");
        else
          puts("NO");
      }
    }
  }
  return 0;
}
