#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n + 1);
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  long long re = n - 2 * m;
  map<long long, long long> f;
  for (long long i = (1); i <= (n); i++) {
    long long dt;
    if (a[i] == i)
      dt = 0;
    else if (a[i] > i)
      dt = n - a[i] + i;
    else
      dt = i - a[i];
    f[dt]++;
  }
  vector<long long> ans;
  for (long long i = (0); i <= (n - 1); i++)
    if (f[i] >= re) ans.emplace_back(i);
  cout << ans.size() << " ";
  for (auto e : ans) cout << e << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
