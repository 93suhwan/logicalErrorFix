#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], ocA[N], ocB[N];
int ans[N];
int n, m;
void solve() {
  cin >> n >> m;
  long long all = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    all += a[i] - b[i];
    ocB[i] = max(0, m - b[i]);
    ocA[i] = min(a[i], m);
    all += m;
    ans[i] = ocB[i];
    all -= 2 * ocB[i];
  }
  for (int i = 1; i <= n; i++) {
    if (all <= 0) continue;
    long long take = min(all / 2, (long long)abs(ocB[i] - ocA[i]));
    all -= 2 * take;
    ans[i] += take;
  }
  cout << abs(all) << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " " << m - ans[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(10);
  int step = 1;
  cin >> step;
  for (int i = 0; i < step; i++) {
    solve();
  }
}
