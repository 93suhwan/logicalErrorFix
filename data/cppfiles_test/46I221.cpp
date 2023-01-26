#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > zh;
int n;
long long a[1005], f[1005];
int main() {
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      zh.push(pair<int, int>(a[i], i));
      continue;
    }
    while (1) {
      if (zh.empty()) break;
      if (a[i] == zh.top().first) {
        ans += a[i];
        f[zh.top().second] = 1;
        zh.pop();
        if (f[i] != -1) f[i] = 1;
        break;
      }
      if (a[i] < zh.top().first) {
        if (f[i] != -1) f[i] = 1;
        ans += a[i];
        zh.top().first -= a[i];
        break;
      }
      ans += zh.top().first;
      a[i] -= zh.top().first;
      f[zh.top().second] = 1;
      f[i] = -1;
      zh.pop();
    }
  }
  long long now = 0;
  for (int i = 2; i <= n; i += 2) {
    if (f[i] == -1 || f[i] == 0) {
      ans += now * (now + 1) / 2;
      now = 0;
    }
    if (f[i] == 1 && f[i + 1] == 1) now++;
  }
  ans += now * (now + 1) / 2;
  cout << ans;
  return 0;
}
