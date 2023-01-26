#include <bits/stdc++.h>
using namespace std;
long long T;
long long b[200009];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> b[i];
  sort(b + 1, b + 1 + n);
  long long cnt = n;
  long long tot = 0;
  long long now = 1;
  long long ans = -1e15;
  while (cnt != 1) {
    b[now] += tot;
    ans = max(ans, b[now]);
    tot -= b[now];
    now++;
    cnt--;
  }
  printf("%lld\n", max(ans, b[now] + tot));
}
signed main() {
  cin >> T;
  while (T--) solve();
}
