#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
struct UN {
  int fa[MAXN], siz, n;
  void init(int _n) {
    siz = _n;
    n = _n;
    for (int i = 1; i <= n; ++i) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[x] = y;
    siz--;
  }
  int count() { return n - siz; }
} un;
int n, m;
int b[MAXN], cnt[MAXN];
int a[MAXN];
bool check(int n, int m, int k) {
  for (int i = 1; i <= n; ++i) {
    a[i] = (((i - 1) - k) % n + n) % n;
    a[i]++;
  }
  un.init(n);
  for (int i = 1; i <= n; ++i) un.merge(a[i], b[i]);
  return un.count() <= m;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i <= n; ++i) cnt[i] = 0;
  for (int i = 1; i <= n; ++i) {
    int k = i - b[i];
    if (k < 0) k += n;
    cnt[k]++;
  }
  vector<int> ans;
  for (int k = 0; k < n; ++k) {
    if (cnt[k] >= n - 2 * m && check(n, m, k)) ans.push_back(k);
  }
  cout << ans.size() << " ";
  for (auto c : ans) cout << c << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
