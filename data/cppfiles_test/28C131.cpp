#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt[n + 1];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    int v = (i - a[i] + 1 + n) % n;
    if (v == 0) v = n;
    cnt[v]++;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (cnt[i] >= n - m)
      ans.push_back(i - 1);
    else if (cnt[i] >= n - 2 * m) {
      vector<int> v(n + 1);
      for (int j = 0; j < n; j++) {
        int ind = i + j;
        if (ind > n) ind -= n;
        v[j + 1] = a[ind];
      }
      int c = 0;
      int j = 1;
      while (j <= n) {
        if (v[j] == j)
          j++;
        else
          swap(v[j], v[v[j]]), c++;
      }
      if (c <= m) ans.push_back(i - 1);
    }
  cout << ans.size() << ' ';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
