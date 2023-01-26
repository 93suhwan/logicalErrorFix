#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int a[N];
int primes[N], cnt;
void init() {
  bool st[N] = {false};
  for (int i = 2; i <= N; i++) {
    if (st[i]) continue;
    primes[cnt++] = i;
    for (int j = i + i; j <= N; j += i) st[j] = true;
  }
}
bool check(int x) {
  int t = x + 1;
  for (int i = lower_bound(primes, primes + cnt, t) - primes; i >= 0; i--)
    if (a[x] % primes[i] != 0) return true;
  return false;
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool succ = true;
    for (int i = n; i >= 1; i--) {
      if (check(i) == false) {
        succ = false;
        break;
      }
    }
    if (succ)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
