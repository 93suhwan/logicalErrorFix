#include <bits/stdc++.h>
using namespace std;
int dx[1000005], dy[1000005];
int first[1000005], second[1000005];
int x1[1000005], Y1[1000005];
int bit1[1000005], bit[1000005];
int n1, m1;
pair<int, int> a[1000005];
void upd(int u, int v) {
  for (; u <= m1; u += u & (-u)) bit[u] += v;
}
int get(int u) {
  int r = 0;
  for (; u > 0; u -= u & (-u)) r += bit[u];
  return r;
}
void upd1(int u, int v) {
  for (; u <= n1; u += u & (-u)) bit1[u] += v;
}
int get1(int u) {
  int r = 0;
  for (; u > 0; u -= u & (-u)) r += bit1[u];
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int k, n, m;
    cin >> n >> m >> k;
    n1 = 0, m1 = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> first[i];
      x1[++n1] = first[i];
    }
    for (int i = 1; i <= m; ++i) {
      cin >> second[i];
      Y1[++m1] = second[i];
    }
    for (int i = 1; i <= n; ++i) dx[first[i]] = 1;
    for (int i = 1; i <= m; ++i) dy[second[i]] = 1;
    for (int i = 1; i <= k; ++i) {
      cin >> a[i].first >> a[i].second;
      Y1[++m1] = a[i].second;
      x1[++n1] = a[i].first;
    }
    sort(x1 + 1, x1 + n1 + 1);
    sort(Y1 + 1, Y1 + m1 + 1);
    n1 = unique(x1 + 1, x1 + n1 + 1) - x1 - 1;
    m1 = unique(Y1 + 1, Y1 + m1 + 1) - Y1 - 1;
    for (int i = 1; i <= n1; ++i) bit1[i] = 0;
    for (int i = 1; i <= m1; ++i) bit[i] = 0;
    sort(a + 1, a + k + 1);
    int j = 1;
    long long res = 0;
    for (int i = 1; i <= k; ++i) {
      while (j <= k && a[j].first != a[i].first) {
        if (dx[a[j].first] && !dy[a[j].second]) {
          int v = lower_bound(Y1 + 1, Y1 + m1 + 1, a[j].second) - Y1;
          upd(v, 1);
        }
        ++j;
      }
      if (dx[a[i].first] && dy[a[i].second]) continue;
      if (dy[a[i].second]) continue;
      int L = lower_bound(second + 1, second + m + 1, a[i].second) - second - 1;
      int R = lower_bound(second + 1, second + m + 1, a[i].second) - second;
      int r = lower_bound(Y1 + 1, Y1 + m1 + 1, second[R]) - Y1;
      int l = lower_bound(Y1 + 1, Y1 + m1 + 1, second[L]) - Y1;
      res += (long long)max(0, get(r - 1) - get(l));
    }
    for (int i = 1; i <= k; ++i) swap(a[i].first, a[i].second);
    sort(a + 1, a + k + 1);
    j = 1;
    for (int i = 1; i <= k; ++i) {
      while (j <= k && a[j].first != a[i].first) {
        if (dy[a[j].first] && !dx[a[j].second]) {
          int v = lower_bound(x1 + 1, x1 + n1 + 1, a[j].second) - x1;
          upd1(v, 1);
        }
        ++j;
      }
      if (dx[a[i].second] && dy[a[i].first]) continue;
      if (dx[a[i].second]) continue;
      int L = lower_bound(first + 1, first + n + 1, a[i].second) - first - 1;
      int R = lower_bound(first + 1, first + n + 1, a[i].second) - first;
      int r = lower_bound(x1 + 1, x1 + n1 + 1, first[R]) - x1;
      int l = lower_bound(x1 + 1, x1 + n1 + 1, first[L]) - x1;
      res += (long long)max(0, get1(r - 1) - get1(l));
    }
    for (int i = 1; i <= n; ++i) dx[first[i]] = 0;
    for (int i = 1; i <= m; ++i) dy[second[i]] = 0;
    cout << res << endl;
  }
}
