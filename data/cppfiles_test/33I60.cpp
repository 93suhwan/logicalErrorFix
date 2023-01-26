#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr int INF = 0x7f7f7f7f;
constexpr int maxn = 501, N = 64;
struct linearbasis {
  int zero = 0;
  int p[N];
  void insert(long long x) {
    for (int i = (int)N - 1; i > (int)-1; --i) {
      if (x >> i & 1) {
        if (!p[i]) {
          p[i] = x;
          return;
        }
        x ^= p[i];
      }
    }
    zero = 1;
  }
  int query(long long x) {
    for (int i = 62; i >= 0; i--)
      if (x & (1LL << i)) x ^= p[i];
    return x == 0;
  }
} A[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  set<pair<int, int>> s;
  vector<int> a(n), vis(1000);
  for (int i = (int)0; i < (int)n; ++i) cin >> a[i];
  for (int i = (int)n - 1; i > (int)-1; --i) {
    if (!vis[a[i]]) A[a[i]].insert(a[i]);
    vis[a[i]] = 1;
    for (int j = a[i] + 1; j < maxn; j++) {
      if (vis[j]) A[j].insert(a[i]);
    }
  }
  set<int> ans;
  ans.insert(0);
  for (int i = (int)0; i < (int)1000; ++i) {
    if (!vis[i]) continue;
    for (int x = (int)0; x < (int)1000; ++x) {
      if (A[i].query(x)) ans.insert(x);
    }
  }
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it << " ";
  cout << "\n";
  return 0;
}
