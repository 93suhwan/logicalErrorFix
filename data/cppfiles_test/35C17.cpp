#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int f[maxn];
int n;
int a[maxn];
char b[maxn];
int g[maxn];
vector<int> stk[maxn], add[maxn];
void sieve() {
  for (int i = 2; i < maxn; ++i) {
    if (f[i] == 0) {
      for (int j = i; j < maxn; j += i) f[j] = i;
    }
  }
}
struct fenwick {
  int sum[maxn];
  void add(int x) {
    for (; x < maxn; x += x & -x) ++sum[x];
  }
  int get(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res += sum[x];
    return res;
  }
  int get(int l, int r) { return get(r) - get(l - 1); }
} tree;
void read_input() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    g[i] = i;
    int x = a[i];
    if (b[i] == '*') {
      g[i] = i;
      while (x > 1) {
        stk[f[x]].push_back(i);
        x /= f[x];
      }
    } else {
      while (x > 1) {
        int p = f[x], lst = i;
        bool flag = false;
        while (f[x] == p) {
          if ((int)stk[p].size()) {
            lst = stk[p].back();
            stk[p].pop_back();
          } else
            flag = true;
          x /= p;
        }
        if (flag)
          g[i] = 0;
        else
          g[i] = min(g[i], lst);
      }
    }
    if (g[i]) add[g[i]].push_back(i);
  }
  long long ans = 0;
  for (int i = n; i > 0; --i) {
    for (auto& p : add[i]) tree.add(p);
    int low = i, high = n;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (tree.get(i, mid) == (mid - i + 1))
        low = mid + 1;
      else
        high = mid - 1;
    }
    ans += high - i + 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  read_input();
  solve();
}
