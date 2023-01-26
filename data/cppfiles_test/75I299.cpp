#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int t, n;
pair<int, int> res[N];
void solve() {
  int k, x, minn, ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    minn = 0;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &x);
      if (x >= minn) minn = x + 1;
      ++minn;
    }
    res[i].first = minn;
    res[i].second = k;
  }
  sort(res, res + n);
  ans = res[0].first - res[0].second;
  long long cur = res[0].first;
  for (int i = 1; i < n; ++i) {
    int temp = res[i].first - res[i].second;
    if (temp > cur) {
      ans += temp - cur;
      cur = res[i].first;
    } else {
      cur += res[i].second;
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    solve();
  }
  return 0;
}
