#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mo = 1e9 + 7;
void solve() {
  long long n, k;
  scanf("%lld", &(n)), scanf("%lld", &(k));
  if (n == 1) {
    puts("0");
    return;
  }
  long long hav = 1;
  long long t = 0;
  while (hav <= k && hav < n) {
    t++;
    hav = hav * 2;
  }
  if (n > hav) {
    t += (n - hav + k - 1) / k;
  }
  printf("%lld\n", t);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
