#include <bits/stdc++.h>
using namespace std;
const int maxs = 14, maxsum = maxs * 1e6 + 5, maxn = 1e3 + 5;
int seen[maxsum], ans[maxn], n;
void no() {
  cout << "NO\n";
  exit(0);
}
void yes() {
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  exit(0);
}
void find_cycle(const vector<int>& v, int m) {
  int h = m >> 1, m1 = -1, m2 = -1;
  for (int i = 0; i < (1 << m); i++)
    if (__builtin_popcount(i) == h) {
      int sum = 0;
      for (int j = 0; j < m; j++)
        if ((i >> j) & 1) sum += v[j];
      if (seen[sum]) {
        m1 = seen[sum];
        m2 = i;
        break;
      }
      seen[sum] = i;
    }
  if (m1 == -1) no();
  int a = m1 & m2;
  m1 ^= a, m2 ^= a;
  vector<int> v1, v2, c;
  for (int i = 0; i < m; i++)
    if ((m1 >> i) & 1) v1.push_back(v[i]);
  for (int i = 0; i < m; i++)
    if ((m2 >> i) & 1) v2.push_back(v[i]);
  for (int i = 0; i < v1.size(); i++) c.push_back(v1[i]), c.push_back(v2[i]);
  ans[0] = 0;
  for (int i = 0; i + 1 < c.size(); i++) ans[i + 1] = c[i] - ans[i];
  int cnt = c.size();
  for (int i = 0; i < n; i++)
    if (i >= m || !(((m1 | m2) >> i) & 1)) ans[cnt++] = v[i] - ans[0];
  yes();
}
int main() {
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > v(2);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i] & 1].push_back(a[i]);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  if (a.size() < n) {
    for (int i = 0; i < a.size(); i++) ans[i] = a[i];
    yes();
  }
  if (v[0].size()) {
    vector<int> x;
    if (v[0].size() >= 3)
      x = {v[0][0], v[0][1], v[0][2]};
    else if (v[1].size() >= 2)
      x = {v[0][0], v[1][0], v[1][1]};
    else
      no();
    for (int i = 0; i < 3; i++)
      ans[i] = (x[i] - x[(i + 1) % 3] + x[(i + 2) % 3]) / 2;
    for (int i = 0; i < 3; i++) a.erase(find(a.begin(), a.end(), x[i]));
    for (int i = 3; i < n; i++) ans[i] = a[i - 3] - ans[0];
    yes();
  }
  find_cycle(a, min(n, 28));
  return 0;
}
