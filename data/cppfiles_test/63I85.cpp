#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
int n, m, ans, tot;
int f[1 << maxn], mn[maxn], cnt[maxn], sum[1 << maxn], tmp[maxn];
vector<int> w[maxn];
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int now = 0;
    cin >> s, mn[i] = 0, cnt[i] = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(')
        now++;
      else {
        now--;
        if (now < mn[i])
          mn[i] = now, cnt[i] = 1;
        else if (now == mn[i])
          cnt[i]++;
      }
      tmp[j] = now;
    }
    sum[1 << (i - 1)] = now;
    w[i].resize(800000);
    int tmpmn = 0;
    for (int j = 0; j < s.size(); j++) {
      tmpmn = min(tmpmn, tmp[j]);
      if (tmpmn == tmp[j]) w[i][400000 + tmp[j]]++;
    }
  }
  f[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    sum[i] = sum[i ^ i & -i] + sum[i & -i];
    for (int j = 1; j <= n; j++)
      if ((i >> (j - 1)) & 1) {
        int pre = (i ^ (1 << (j - 1))), v = f[pre];
        if (sum[pre] < 0) continue;
        if (sum[pre] == -mn[j])
          v += cnt[j];
        else if (sum[pre] < -mn[j])
          v = -1;
        f[i] = max(f[i], v);
        if (sum[pre] >= 0) ans = max(ans, f[pre] + w[j][400000 - sum[pre]]);
      }
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
  return 0;
}
