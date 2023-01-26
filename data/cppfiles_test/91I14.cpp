#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 6;
int a[lim], n;
vector<int> q[2];
int cnt[2][lim];
long long get() {
  long long res = 0;
  int now, pre, k;
  now = 0;
  pre = 1;
  q[now].push_back(a[n]);
  cnt[now][a[n]] = 1;
  for (int i = n - 1; i > 0; --i) {
    now ^= 1;
    pre ^= 1;
    for (auto v : q[pre]) {
      k = (a[i] + v - 1) / v;
      res += 1ll * cnt[pre][v] * (k - 1) * i;
      if (cnt[now][a[i] / k] == 0) q[now].push_back(a[i] / k);
      cnt[now][a[i] / k] += cnt[pre][v];
    }
    if (cnt[now][a[i]] == 0) q[now].push_back(a[i]);
    cnt[now][a[i]]++;
    for (auto v : q[pre]) cnt[pre][v] = 0;
    q[pre].clear();
  }
  for (auto v : q[now]) cnt[now][v] = 0;
  q[now].clear();
  return res;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << get() << '\n';
  }
  return 0;
}
