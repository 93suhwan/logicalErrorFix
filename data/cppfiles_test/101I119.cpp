#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int ma = INT_MAX;
const int mod = 998244353;
struct point {
  int x, y;
} p[N];
int l[N], r[N], visl[N * 10], visr[N * 10], a[N], b[N];
bool cmp1(int a, int b) { return p[a].y < p[b].y; }
bool cmp2(int a, int b) { return p[a].x < p[b].x; }
map<int, int> mp;
signed main() {
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  int _, n, k, m;
  string s;
  cin >> _;
  while (_--) {
    cin >> n >> m >> k;
    memset(visl, 0, sizeof visl);
    memset(visr, 0, sizeof visr);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) cin >> l[i], visl[l[i]] = 1;
    for (int i = 1; i <= m; i++) cin >> r[i], visr[r[i]] = 1;
    for (int i = 1; i <= k; i++) {
      cin >> p[i].x >> p[i].y;
      if (visl[p[i].x] && visr[p[i].y]) continue;
      if (visl[p[i].x])
        b[++cnt2] = i;
      else
        a[++cnt1] = i;
    }
    sort(a + 1, a + 1 + cnt1, cmp2);
    sort(b + 1, b + 1 + cnt2, cmp1);
    int j = 1;
    int al = 0;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      al = 0;
      while (p[a[j]].x > l[i] && p[a[j]].x < l[i + 1] && j <= cnt1) {
        mp[p[a[j]].y]++;
        j++;
        al++;
      }
      for (auto h : mp) {
        al -= h.second;
        ans += (long long)al * h.second;
      }
      mp.clear();
    }
    j = 1, al = 0;
    for (int i = 1; i < m; i++) {
      al = 0;
      while (p[b[j]].y > r[i] && p[b[j]].y < r[i + 1] && j <= cnt2) {
        mp[p[b[j]].y]++;
        j++;
        al++;
      }
      for (auto h : mp) {
        al -= h.second;
        ans += (long long)al * h.second;
      }
      mp.clear();
    }
    cout << ans << '\n';
  }
  return 0;
}
