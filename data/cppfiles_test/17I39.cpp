#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 1e5 + 29;
int a[N], b[N];
int c[N];
void add(int x, int v, int cnt) {
  while (x <= cnt) {
    c[x] += v;
    x += x & -x;
  }
}
int get(int x) {
  int ans = 0;
  while (x) {
    ans += c[x];
    x -= x & -x;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int cnt = unique(b + 1, b + 1 + n) - b - 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    int x = get(p - 1);
    int y = get(cnt) - get(p);
    ans += min(x, y);
    add(p, 1, cnt);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
