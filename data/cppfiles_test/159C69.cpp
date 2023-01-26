#include <bits/stdc++.h>
using namespace std;
int n, ans;
mt19937_64 rng(1919810);
unsigned long long h[1000005];
bitset<1000005> bs, pri;
unordered_map<unsigned long long, int> mp;
int main() {
  scanf("%d", &n), ans = n;
  for (int i = 2; i <= n; i++)
    if (!pri[i]) {
      unsigned long long H = rng();
      unsigned long long d = 1;
      for (;;) {
        d *= i;
        if (d > n) break;
        for (int j = d; j <= n; j += d) h[j] ^= H, pri[j] = 1;
      }
    }
  for (int i = 2; i <= n; i++) h[i] ^= h[i - 1];
  unsigned long long H = 0;
  for (int i = 1; i <= n; i++) H ^= h[i];
  if (H == 0)
    ans = n;
  else {
    bool ok = 0;
    ans--;
    for (int i = 1; i <= n; i++)
      if (h[i] == H) {
        bs[i] = 1;
        ok = 1;
        break;
      }
    if (!ok) {
      bool ok = 0;
      ans--;
      for (int i = 1; i <= n; i++) {
        if (mp.find(h[i]) != mp.end()) {
          bs[mp[h[i]]] = 1;
          bs[i] = 1;
          ok = 1;
          break;
        }
        mp[H ^ h[i]] = i;
      }
      if (!ok) {
        ans--;
        bs[2] = 1;
        bs[(n - 1) / 2] = 1;
        bs[n] = 1;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (bs[i] == 0) printf("%d ", i);
}
