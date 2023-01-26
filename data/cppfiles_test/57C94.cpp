#include <bits/stdc++.h>
using namespace std;
long long s, n, k;
inline void solve() {
  scanf("%lld %lld %lld", &s, &n, &k);
  if (s < k) return (void)(puts("NO"));
  if (s == k) return (void)(puts("YES"));
  if (n == 1) return (void)(puts("NO"));
  long long sum = (n / k) * (2 * k) + (n % k);
  if (sum <= s)
    puts("NO");
  else
    puts("YES");
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
