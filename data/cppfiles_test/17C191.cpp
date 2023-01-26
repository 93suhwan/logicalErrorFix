#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int a[maxn], dist[maxn], cnt, sum[maxn];
int lowbit(int x) { return x & -x; }
void add(int x, int c) {
  while (x <= cnt) {
    sum[x] += c;
    x += lowbit(x);
  }
}
int ask(int x) {
  int ans = 0;
  while (x) {
    ans += sum[x];
    x -= lowbit(x);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], dist[++cnt] = a[i], sum[i] = 0;
    sort(dist + 1, dist + 1 + cnt);
    cnt = unique(dist + 1, dist + 1 + cnt) - dist - 1;
    for (int i = 1; i <= n; i++)
      a[i] = lower_bound(dist + 1, dist + 1 + cnt, a[i]) - dist;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int l = ask(a[i] - 1);
      int r = ask(cnt) - ask(a[i]);
      ans += min(l, r);
      add(a[i], 1);
    }
    cout << ans << endl;
  }
  return 0;
}
