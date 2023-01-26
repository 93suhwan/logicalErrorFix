#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
pair<int, int> p[maxn];
int a[maxn], b[maxn], g[301][301];
int tree[maxn], rt;
void add(int x, int val) {
  for (int i = x; i <= rt; i += i & -i) {
    tree[i] += val;
  }
}
long long sum(int x) {
  long long res = 0;
  for (int i = x; i; i -= i & -i) {
    res += tree[i];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int nm = n * m;
    for (int i = 1; i <= nm; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + nm + 1);
    int tot = unique(b + 1, b + nm + 1) - (b + 1);
    for (int i = 1; i <= nm; ++i) {
      a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
      p[i] = {a[i], i};
    }
    sort(p + 1, p + nm + 1);
    int k = 1;
    for (int r = 0, l = 1; r <= nm; ++r) {
      if (r < nm && p[r + 1].first == p[l].first) continue;
      int pos = (l - 1) % m + 1;
      while (l <= r) {
        if (r - l + 1 + pos - 1 >= m) {
          for (int i = m; i >= pos; --i) {
            g[k][i] = p[l++].second;
          }
          pos = 1;
          k++;
        } else {
          int len = r - l;
          for (int i = pos + len; i >= pos; --i) {
            g[k][i] = p[l++].second;
          }
          pos += len;
        }
      }
      if (r != nm) r--;
    }
    long long ans = 0;
    rt = nm;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        ans += sum(g[i][j]);
        add(g[i][j], 1);
      }
      for (int j = 1; j <= m; ++j) {
        add(g[i][j], -1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
