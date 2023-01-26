#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
int T;
int n, m, k;
int xx[MAXN], yy[MAXN];
bool visx[MAXN], visy[MAXN];
long long sum[MAXN];
vector<pair<int, int> > v1, v2;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool ok(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second != b.second;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    v1.clear();
    v2.clear();
    for (int i = 1; i <= n; i++) {
      cin >> xx[i];
      visx[xx[i]] = 1;
    }
    for (int i = 1; i <= m; i++) {
      cin >> yy[i];
      visy[yy[i]] = 1;
    }
    for (int i = 1; i <= k; i++) {
      int tpx, tpy;
      cin >> tpx >> tpy;
      if (visx[tpx] && visy[tpy]) continue;
      if (visx[tpx]) {
        v1.push_back(
            pair<int, int>(tpx, lower_bound(yy + 1, yy + m + 1, tpy) - yy));
      } else {
        v2.push_back(
            pair<int, int>(tpy, lower_bound(xx + 1, xx + n + 1, tpx) - xx));
      }
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    long long ans = 0;
    long long st = -1, now = 0;
    for (int i = 0; i < v1.size() - 1; i++) {
      if (ok(v1[i], v1[i + 1])) {
        ans += sum[v1[i].second] * (now + 1);
        sum[v1[i].second] += (now + 1);
        now = 0;
        if (i == v1.size() - 2) now++;
      } else
        now++;
    }
    ans += sum[v1[v1.size() - 1].second] * now;
    swap(v1, v2);
    for (int i = 0; i <= n; i++) sum[i] = 0;
    st = -1, now = 0;
    for (int i = 0; i < v1.size() - 1; i++) {
      if (ok(v1[i], v1[i + 1])) {
        ans += sum[v1[i].second] * (now + 1);
        sum[v1[i].second] += (now + 1);
        now = 0;
        if (i == v1.size() - 2) now++;
      } else
        now++;
    }
    ans += sum[v1[v1.size() - 1].second] * now;
    for (int i = 0; i <= m; i++) sum[i] = 0;
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
      visx[xx[i]] = 0;
    }
    for (int i = 1; i <= m; i++) {
      visy[yy[i]] = 0;
    }
  }
  return 0;
}
