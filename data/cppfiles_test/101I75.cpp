#include <bits/stdc++.h>
using namespace std;
char c[200009];
long long T;
long long n;
long long a[200009];
long long b[200009];
long long d[200009];
long long vis[200009];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    vis[i] = 0;
    b[i] = 0;
    d[i] = 0;
  }
  cin >> c + 1;
  for (long long i = 1; i <= n; i++) {
    if (c[i] == 'R') {
      if (a[i] > n) continue;
      d[a[i] - 1]--;
      d[n]++;
    }
    if (c[i] == 'B') {
      if (a[i] < 1) continue;
      b[1]++;
      b[a[i] + 1]--;
    }
  }
  long long sum = 0;
  long long last = 0;
  long long tot = 0;
  for (long long i = 1; i <= n; i++) {
    sum += b[i];
    if (sum == 0) break;
    if (sum != last) {
      tot = sum;
      last = sum;
    }
    if (tot != 0) tot--, vis[i] = 1;
  }
  sum = 0, last = 0, tot = 0;
  for (long long i = n; i >= 1; i--) {
    sum += d[i];
    if (sum == 0) break;
    if (sum != last) {
      tot = sum;
      last = sum;
    }
    if (tot != 0 && vis[i] == 0) tot--, vis[i] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
signed main() {
  cin >> T;
  while (T--) solve();
}
