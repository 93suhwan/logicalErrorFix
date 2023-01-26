#include <bits/stdc++.h>
using namespace std;
char c[200009];
int T;
int n;
int a[200009];
int b[200009];
int d[200009];
int vis[200009];
void solve() {
  cin >> n;
  b[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vis[i] = 0;
    b[i] = 0;
    d[i] = 0;
  }
  cin >> c + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > n && c[i] == 'R') {
      printf("NO\n");
      return;
    }
    if (a[i] < 1 && c[i] == 'B') {
      printf("NO\n");
      return;
    }
    if (c[i] == 'R') a[i] = max(a[i], 0);
    if (c[i] == 'B') a[i] = min(a[i], n);
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'R') {
      d[a[i] - 1]--;
      d[n]++;
    }
    if (c[i] == 'B') {
      b[1]++;
      b[a[i] + 1]--;
    }
  }
  int sum = 0;
  int last = 0;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    sum += b[i];
    if (sum == 0) break;
    if (sum != last) {
      tot = sum;
      last = sum;
    }
    if (tot != 0) tot--, vis[i] = 1;
  }
  sum = 0, last = 0, tot = 0;
  for (int i = n; i >= 1; i--) {
    sum += d[i];
    if (sum == 0) break;
    if (sum != last) {
      tot = sum;
      last = sum;
    }
    if (tot != 0) tot--, vis[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
int main() {
  cin >> T;
  while (T--) solve();
}
