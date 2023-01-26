#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
int n, sz = 4;
int a[200010];
long long ans[200010];
long long s, cnt;
int num[666];
int dp[666][666];
struct BIT {
  long long tree[400010];
  BIT() { memset(tree, 0, sizeof(tree)); }
  void update(int i, int x) {
    while (i <= sz * sz) {
      tree[i] += x;
      i += i & -i;
    }
  }
  long long sum(int i) {
    long long ret = 0;
    while (i) {
      ret += tree[i];
      i -= i & -i;
    }
    return ret;
  }
} t1, t2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > sz) {
      ans[i] += t1.sum(a[i]) + cnt * a[i];
      ans[i] += s;
      for (int j = a[i]; j <= sz * sz; j += a[i]) {
        t1.update(j, -a[i]);
        ans[i] -= (j / a[i]) * (t2.sum(j + a[i] - 1) - t2.sum(j - 1)) * a[i];
      }
      cnt++;
      for (int j = 2; j <= sz; j++) {
        ans[i] += num[j] * (a[i] % j);
      }
    } else {
      for (int j = 1; j < a[i]; j++) {
        ans[i] += j * dp[a[i]][j];
      }
      for (int j = 2; j < a[i]; j++) {
        ans[i] += num[j] * (a[i] % j);
      }
      ans[i] += (i - t2.sum(a[i]) - 1) * a[i];
      num[a[i]]++;
    }
    s += a[i];
    t2.update(a[i], 1);
    for (int j = 2; j <= sz; j++) {
      dp[j][a[i] % j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    cout << ans[i] << " ";
  }
}
