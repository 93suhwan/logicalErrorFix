#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
inline int lowbit(int x) { return x & -x; }
int bit[N], cnt;
void add(int x, int val) {
  for (int i = x; i <= cnt; i += lowbit(i)) bit[i] += val;
}
int sum(int x) {
  int ret = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ret += bit[i];
  return ret;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> aa;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      aa.emplace_back(a[i]);
    }
    sort(aa.begin(), aa.end());
    aa.erase(unique(aa.begin(), aa.end()), aa.end());
    cnt = aa.size();
    memset(bit, 0, sizeof(bit));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x = lower_bound(aa.begin(), aa.end(), a[i]) - aa.begin() + 1;
      ans += min(sum(x - 1), sum(cnt) - sum(x));
      add(x, 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
