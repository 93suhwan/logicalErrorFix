#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e6 + 7;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
void solve() {
  long long n, m, k;
  scanf("%lld%lld%lld", &n, &m, &k);
  if (n == 1 && m == 0) {
    if (k > 1)
      puts("YES");
    else
      puts("NO");
  } else if (n == 1)
    puts("NO");
  else if ((m < n - 1) || (m > (n * (n - 1) / 2)))
    puts("NO");
  else if ((n == 2 && m == 1) || (m == (n * (n - 1) / 2))) {
    if (k > 2)
      puts("YES");
    else
      puts("NO");
  } else {
    if (k > 3)
      puts("YES");
    else
      puts("NO");
  }
}
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) solve();
  return 0;
}
