#include <bits/stdc++.h>
using namespace std;
long long n, m1, m2, x, y;
long long f1[1000005], f2[1000005];
bool vis[1000005];
vector<long long> ans1, ans2;
long long find(long long x, long long *f) {
  if (x != f[x]) f[x] = find(f[x], f);
  return f[x];
}
bool check(long long x, long long y, long long *f) {
  if (find(x, f) == find(y, f)) return 1;
  return 0;
}
void merge(long long x, long long y, long long *f) {
  long long ex = find(x, f), ey = find(y, f);
  if (ex == ey) return;
  f[ex] = ey;
}
signed main() {
  cin >> n >> m1 >> m2;
  for (long long i = 1; i <= n; i++) f1[i] = f2[i] = i;
  for (long long i = 1; i <= m1; i++) {
    cin >> x >> y;
    merge(x, y, f1);
  }
  for (long long i = 1; i <= m2; i++) {
    cin >> x >> y;
    merge(x, y, f2);
  }
  for (long long i = 1; i <= 1; i++) {
    for (long long j = 2; j <= n; j++) {
      if (!check(i, j, f1) && !check(i, j, f2)) {
        ans1.push_back(i), ans2.push_back(j);
        merge(i, j, f1), merge(i, j, f2);
        vis[j] = 1;
      }
    }
  }
  for (long long i = 2; i <= n; i++) {
    if (vis[i]) continue;
    if (!check(1, i, f1)) ans1.push_back(i), merge(1, i, f1);
    if (!check(1, i, f2)) ans2.push_back(i), merge(1, i, f2);
  }
  cout << min(ans1.size(), ans2.size()) << endl;
  for (long long i = 0; i < ans1.size() && i < ans2.size(); i++)
    cout << ans1[i] << ' ' << ans2[i] << endl;
}
