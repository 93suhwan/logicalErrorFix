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
  if (m < n - 1) {
    puts("NO");
    return;
  }
  if (n > 1 && k == 1) {
    puts("NO");
    return;
  }
  int d = n - 1;
  k--;
  int p = 1;
  m -= (n - 1);
  if (m > 0) {
    m--;
    d = (d + 1) / 2;
    p *= 2;
  }
  while (m >= p) {
    m -= p;
    d = d / 2;
    p *= 2;
    if (d % 2 == 0) d++;
  }
  if (d < k)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
