#include <bits/stdc++.h>
using namespace std;
const long long int INF = 3e18;
const int inf = 1e9 + 10;
const int maxn = 200 + 10;
const int maxi = 4 * maxn;
const int mod = 1e9 + 7;
const int LOG = 25;
void solve() {
  int n;
  vector<int> vec;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }
  sort(vec.begin(), vec.end());
  bool flag = 0;
  for (int i : vec)
    if (i == 0) flag = 1;
  for (int i = 1; i < vec.size(); i++)
    if (vec[i] == vec[i - 1]) flag = 1;
  if (flag) {
    cout << "YES\n";
    return;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    long long int cnt = 0;
    for (int i = 0; i < vec.size(); i++)
      if (mask & (1 << i)) cnt += vec[i];
    for (int mask2 = 1; mask2 < (1 << n); mask2++) {
      if (mask + mask2 != (mask | mask2)) continue;
      long long int cnt2 = 0;
      for (int i = 0; i < vec.size(); i++)
        if ((1 << i) & mask2) cnt2 += vec[i];
      if (cnt2 == cnt) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
