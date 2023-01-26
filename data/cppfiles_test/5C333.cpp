#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
int n, m;
char a[N], b[N];
void solve() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] == '1') {
      if (a[i] == '0' || a[i - 1] == '1')
        ++res;
      else if (a[i + 1] == '1') {
        a[i + 1] = '*';
        ++res;
      }
    }
  }
  printf("%d\n", res);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
