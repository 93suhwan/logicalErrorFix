#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  vector<pair<long long, long long> > b(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<long long> can(n, 0);
  vector<long long> x(n);
  vector<long long> y(n);
  vector<pair<long long, long long> > pos(n);
  for (long long i = 0; i < n; i++) {
    pos[a[i].second].first = i;
    pos[b[i].second].second = i;
  }
  for (long long i = 0; i < n; i++) {
    x[i] = pos[a[i].second].second;
    y[i] = pos[b[i].second].first;
  }
  long long minx = y.back();
  long long miny = x.back();
  vector<long long> sufx = x;
  vector<long long> sufy = y;
  for (long long i = n - 2; i >= 0; i--) {
    sufx[i] = min(sufx[i], sufx[i + 1]);
    sufy[i] = min(sufy[i], sufy[i + 1]);
  }
  for (long long i = 0; i < 2 * n + 10; i++) {
    miny = min(miny, sufx[minx]);
    minx = min(minx, sufy[miny]);
  }
  for (long long i = minx; i < n; i++) {
    can[a[i].second] = 1;
  }
  for (long long i = miny; i < n; i++) {
    can[b[i].second] = 1;
  }
  for (long long i : can) cout << i;
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
}
