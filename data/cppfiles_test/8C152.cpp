#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
const long long mod = 1e9 + 7;
int n;
void solve() {
  scanf("%d", &n);
  if (n % 3 == 0)
    printf("%d %d\n", n / 3, n / 3);
  else if (n % 3 == 1)
    printf("%d %d\n", n / 3 + 1, n / 3);
  else
    printf("%d %d\n", n / 3, n / 3 + 1);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
}
