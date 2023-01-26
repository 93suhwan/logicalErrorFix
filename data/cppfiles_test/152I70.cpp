#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 100;
void tmax(int& a, int b) { a = max(a, b); }
void tmin(int& a, int b) { a = min(a, b); }
int a[N], pos[N], ans[N];
bool done[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  fill(done, done + n, 0);
  int ml, cl, md, cd, tl, dr;
  ml = cl = -INF;
  md = cd = +INF;
  tl = 0;
  dr = n - 1;
  for (int i = n; i >= 1 && tl <= dr; i--) {
    if (done[i]) continue;
    int bm = pos[i];
    bool lef = 1;
    int apl = ml;
    for (int j = tl; j < bm; j++) {
      if (a[j] < apl) {
        lef = 0;
        break;
      }
      if (-a[j] > apl) {
        ans[j] = -a[j];
        tmax(apl, ans[j]);
      } else {
        ans[j] = a[j];
        tmax(apl, ans[j]);
      }
    }
    bool rig = 1;
    int apr = cd;
    for (int j = dr; j > bm; j--) {
      if (-a[j] > apr) {
        rig = 0;
        break;
      }
      if (a[j] < apr) {
        ans[j] = a[j];
        tmin(apr, ans[j]);
      } else {
        ans[j] = -a[j];
        tmin(apr, ans[j]);
      }
    }
    if (-i > apr) lef = 0;
    if (i < apl) rig = 0;
    if (!lef && !rig) {
      cout << "NO" << '\n';
      return;
    }
    if (lef) {
      ans[bm] = -i;
      for (int j = tl; j <= bm; j++) done[a[j]] = 1;
      cl = -i;
      ml = apl;
      tl = bm + 1;
    } else {
      ans[bm] = i;
      for (int j = dr; j >= bm; j--) done[a[j]] = 1;
      md = i;
      cd = apr;
      dr = bm - 1;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
