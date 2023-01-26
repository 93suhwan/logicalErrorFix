#include <bits/stdc++.h>
using namespace std;
const int MAX = 202020;
const int INF = 1e9;
const long long LINF = 1e18;
int x[MAX], y[MAX], sum[MAX];
class BinaryIndexedTree {
  vector<int> tree;
  int sz;

 public:
  void Init(int n) {
    tree.resize(n + 1);
    sz = n;
  }
  void update(int i, int val) {
    while (i <= sz) {
      tree[i] += val;
      i += (i & -i);
    }
  }
  int cal(int i) {
    int ret = 0;
    while (i > 0) {
      ret += tree[i];
      i -= (i & -i);
    }
    return ret;
  }
} BIT[404];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  int sz = (int)sqrt(m);
  for (int i = 1; i <= sz; i++) {
    BIT[i].Init(i);
  }
  map<int, int> on;
  int num = 0;
  for (int i = 1; i <= m; i++) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] > sz) {
        for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
          sum[j]++;
        }
        for (int j = i + x[k] + y[k]; j <= m; j += x[k] + y[k]) {
          sum[j]--;
        }
      } else {
        int ss = x[k] + y[k];
        BIT[ss].update((i + x[k]) % ss + 1, 1);
        BIT[ss].update(i % ss + 1, -1);
        if ((i + x[k]) % ss > i % ss) {
          BIT[ss].update(1, 1);
          BIT[ss].update(ss, -1);
        }
      }
      on[k] = i;
    } else {
      if (x[k] + y[k] > sz) {
        int st = on[k];
        for (int j = st + x[k]; j <= m; j += x[k] + y[k]) sum[j]--;
        for (int j = st + x[k] + y[k]; j <= m; j += x[k] + y[k]) sum[j]++;
      } else {
        int ss = x[k] + y[k], st = on[k];
        BIT[ss].update((st + x[k]) % ss + 1, -1);
        BIT[ss].update(st % ss + 1, 1);
        if ((st + x[k]) % ss > st % ss) {
          BIT[ss].update(1, -1);
          BIT[ss].update(ss, 1);
        }
      }
      on.erase(k);
    }
    num += sum[i];
    int ans = num;
    for (int j = 2; j <= sz; j++) {
      ans += BIT[j].cal((i % j) + 1);
    }
    cout << ans << '\n';
  }
}
