#include <bits/stdc++.h>
using namespace std;
string alphabet =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
long long pd = 998244353;
long long tc;
void solve() {
  int n;
  cin >> n;
  int x[n + 10], y[n + 10];
  pair<int, pair<int, pair<int, int>>> p[n + 10];
  for (int i = 1; i <= n; i++) {
    int z;
    cin >> x[i] >> y[i] >> z;
    int m = x[i] - z;
    pair<int, pair<int, int>> t =
        make_pair(max(m, 0), make_pair(min(y[i] - z, 0) + x[i], i));
    p[i] = make_pair(x[i] + y[i] - z, t);
  }
  sort(p + 1, p + 1 + n);
  int i = 1, dem = 0;
  pair<int, int> kq[n + 10];
  p[n + 1].first = -1;
  while (i <= n) {
    int j = i;
    while (p[i].first == p[j].first) j++;
    j--;
    int r = p[i].second.second.first, pre = i;
    for (int ii = i; ii <= j; ii++) {
      if (p[ii].second.first > r) {
        dem++;
        for (int jj = pre; jj < ii; jj++)
          kq[p[jj].second.second.second] = make_pair(r, p[i].first - r);
        pre = ii;
        r = p[ii].second.second.first;
      } else {
        r = min(r, p[ii].second.second.first);
      }
    }
    for (int jj = pre; jj <= j; jj++)
      kq[p[jj].second.second.second] = make_pair(r, p[i].first - r);
    dem++;
    i = j + 1;
  }
  cout << dem << endl;
  for (int i = 1; i <= n; i++) {
    cout << x[i] - kq[i].first << " " << y[i] - kq[i].second << endl;
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
