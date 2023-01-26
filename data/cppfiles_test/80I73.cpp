#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500020;
const int maxm = 10000020;
const int MOd = 998244353;
int a, b, ar[maxn], bs[maxn], sz[maxn];
long long n, segment[maxn * 2], lazy[maxn * 2];
vector<int> w[maxn], v;
void push(int k) {
  if (lazy[k]) {
    if (k < n) {
      lazy[k + k] += lazy[k];
      lazy[k + k + 1] += lazy[k];
    }
    segment[k] += lazy[k];
    lazy[k] = 0;
  }
}
void up(int k, int b, int s, int x, int y, int m) {
  push(k);
  if (b > y || x > s) return;
  if (x <= b && s <= y) {
    lazy[k] += m;
    push(k);
    return;
  }
  up(k + k, b, (b + s) / 2, x, y, m);
  up(k + k + 1, (b + s) / 2 + 1, s, x, y, m);
  segment[k] = min(segment[k + k], segment[k + k + 1]);
}
int fw[maxn], cnt;
int find(int x) {
  int ret = 0;
  for (int i = x; i <= cnt; i += i & (-i)) ret += fw[i];
  return ret;
}
void fup(int x) {
  for (int i = x; i > 0; i -= i & (-i)) fw[i] += 1;
}
void solve() {
  scanf("%d %d", &a, &b);
  v.clear();
  for (int i = 1; i <= a; i++) scanf("%d", &ar[i]), v.push_back(ar[i]);
  for (int i = 1; i <= b; i++) scanf("%d", &bs[i]), v.push_back(bs[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cnt = v.size();
  n = 1;
  while (n < a + 1) n <<= 1;
  for (int i = 1; i <= n + n; i++) segment[i] = lazy[i] = sz[i] = 0;
  for (int i = 0; i <= cnt; i++) fw[i] = 0;
  for (int i = 1; i <= a; i++)
    ar[i] = lower_bound(v.begin(), v.end(), ar[i]) - v.begin() + 1;
  for (int i = 1; i <= b; i++)
    bs[i] = lower_bound(v.begin(), v.end(), bs[i]) - v.begin() + 1, sz[bs[i]]++;
  ;
  for (int i = 1; i <= a; i++) w[ar[i]].push_back(i), up(1, 1, n, i + 1, n, 1);
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    ans += find(ar[i] + 1);
    fup(ar[i]);
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j < w[i].size(); j++) up(1, 1, n, w[i][j] + 1, n, -1);
    push(1);
    ans += (long long)segment[1] * sz[i];
    for (int j = 0; j < w[i].size(); j++) up(1, 1, n, 1, w[i][j], 1);
  }
  cout << ans << endl;
  for (int i = 1; i <= cnt; i++) w[i].clear();
}
int main() {
  int n = 1;
  scanf("%d", &n);
  while (n--) solve();
  return 0;
}
