#include <bits/stdc++.h>
using namespace std;
long long s, n, k;
inline void solve() {
  scanf("%lld %lld %lld", &s, &n, &k);
  if (s < k) return (void)(puts("NO"));
  if (n == 1) return (void)(puts((s == k) ? "YES" : "NO"));
  if (s != k)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
