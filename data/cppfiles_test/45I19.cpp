#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
vector<int> c[2];
void solve() {
  c[0].clear();
  c[1].clear();
  int n;
  cin >> n;
  int o = 0, e = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], o += a[i] % 2, e += a[i] % 2 == 0;
  if (abs(o - e) > 1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    a[i] &= 1;
    c[a[i]].push_back(i);
    a[i] = i;
  }
  vector<int> t1 = {-1};
  int curr1 = 0, curr2 = 0;
  bool now = 0;
  while (curr1 < c[0].size() && curr2 < c[1].size()) {
    if (now)
      t1.push_back(c[now][curr2]), ++curr2;
    else
      t1.push_back(c[now][curr1]), ++curr1;
    now = !now;
  }
  while (curr1 < c[0].size()) t1.push_back(c[0][curr1]), ++curr1;
  while (curr2 < c[1].size()) t1.push_back(c[1][curr2]), ++curr2;
  vector<int> t2 = {-1};
  curr1 = 0, curr2 = 0;
  now = 1;
  while (curr1 < c[0].size() && curr2 < c[1].size()) {
    if (now)
      t2.push_back(c[now][curr2++]);
    else
      t2.push_back(c[now][curr1++]);
    now = !now;
  }
  while (curr1 < c[0].size()) t2.push_back(c[0][curr1++]);
  while (curr2 < c[1].size()) t2.push_back(c[1][curr2++]);
  int dist1 = 0, dist2 = 0;
  for (int i = 1; i <= n; i++)
    dist1 += abs(t1[i] - a[i]), dist2 += abs(t2[i] - a[i]);
  if (n % 2 == 0) {
    cout << min(dist1, dist2) / 2 << '\n';
    return;
  }
  if (c[0].size() > c[1].size())
    cout << dist1 / 2 << '\n';
  else
    cout << dist2 / 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  for (cin >> t; t--;) solve();
}
