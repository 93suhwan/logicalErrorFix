#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 100;
const int INF = 0x7fffffff;
const int mod = 998244353;
const long long mod1 = 998244353;
const long long base = 137;
const double Pi = acos(-1.0);
const int G = 3;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 2 * n - 2 * i; j++) {
        a[j] = (j - 1) % 2;
      }
      for (int j = 2 * n - 2 * i + 1; j <= 2 * n - i; j++) {
        a[j] = 0;
      }
      for (int j = 2 * n - i + 1; j <= 2 * n; j++) a[j] = 1;
      for (int j = 1; j <= 2 * n; j++) {
        if (a[j])
          printf(")");
        else
          printf("(");
      }
      puts("");
    }
  }
}
