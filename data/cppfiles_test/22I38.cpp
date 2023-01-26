#include <bits/stdc++.h>
using namespace std;
const int MAX = 202020;
const int INF = 1e9;
const long long LINF = 1e18;
int x[MAX], y[MAX], sum[MAX];
int q[404][404];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  int sz = (int)sqrt(m);
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
        for (int j = (i + x[k] - 1) % ss + 1; j < (i % ss) + ss; j++) {
          q[ss][j % ss]++;
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
        for (int j = (st + x[k] - 1) % ss + 1; j < (st % ss) + ss; j++) {
          q[ss][j % ss]--;
        }
      }
      on.erase(k);
    }
    num += sum[i];
    int ans = num;
    for (int j = 2; j <= sz; j++) {
      ans += q[j][i % j];
    }
    cout << ans << '\n';
  }
}
