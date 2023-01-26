#include <bits/stdc++.h>
using namespace std;
template <class Num>
Num mabs(Num x) {
  if (x < 0) return -x;
  return x;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  k -= 2;
  long long svi = (long long)n * (n - 1) / 2ll;
  if ((long long)m > svi) {
    puts("NO");
    return;
  }
  if (m < n - 1) {
    puts("NO");
    return;
  }
  if (k <= -1) {
    puts("NO");
    return;
  }
  if (k == 0) {
    if (n == 1) {
      puts("YES");
      return;
    } else {
      puts("NO");
      return;
    }
  }
  if (k == 1) {
    if (svi == (long long)m)
      puts("YES");
    else
      puts("NO");
    return;
  }
  puts("YES");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
