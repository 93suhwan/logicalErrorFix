#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
long long a[200005];
int l[200005];
int r[200005];
pair<int, int> b[200005];
pair<int, int> c[200005];
int sb, second;
long long f[200005][2];
long long pr[200005][2];
void sol() {
  cin >> n >> m;
  sb = second = 0;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], pr[i][0] = pr[i][1] = 3ll * 1000000007;
  a[n + 1] = 10ll * 1000000007;
  n++;
  pr[n][0] = pr[n][1] = 3ll * 1000000007;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> l[i] >> r[i];
    int L = lower_bound(a + 1, a + n + 1, l[i]) - a;
    int R = upper_bound(a + 1, a + n + 1, r[i]) - a - 1;
    if (L > R) b[++sb] = pair<int, int>(l[i], -r[i]);
  }
  sort(b + 1, b + sb + 1);
  int minn = 1000000007;
  for (int i = sb; i >= 1; --i)
    if (minn > -b[i].second)
      c[++second] = pair<int, int>(b[i].first, -b[i].second),
      minn = -b[i].second;
  reverse(c + 1, c + second + 1);
  if (c[1].second < a[1]) {
    f[1][0] = a[1] - c[1].second;
    f[1][1] = 2 * (a[1] - c[1].second);
  } else
    f[1][0] = f[1][1] = 0;
  for (int i = 1; i <= second; ++i) {
    long long res1 = 0;
    long long res2 = 0;
    int L = lower_bound(a + 1, a + n + 1, c[i].first) - a - 1;
    if (!L) continue;
    int R =
        lower_bound(c + 1, c + second + 1, pair<int, int>(c[i].second + 1, 0)) -
        c;
    if (R == second + 1 || c[R].first > a[L + 1])
      res1 = res1;
    else
      res1 += a[L + 1] - c[R].second, res2 += 2 * (a[L + 1] - c[R].second);
    res1 += c[i].first - a[L];
    res2 += c[i].first - a[L];
    pr[L + 1][0] = min(pr[L + 1][0], res1);
    pr[L + 1][1] = min(pr[L + 1][1], res2);
    if (i == 1 || c[i - 1].first < a[L])
      pr[L + 1][0] = min(pr[L + 1][0], a[L + 1] - c[i].second),
             pr[L + 1][0] = min(pr[L + 1][0], 2 * a[L + 1] - 2 * c[i].second);
  }
  for (int i = 2; i <= n; ++i) {
    int L =
        lower_bound(c + 1, c + second + 1, pair<int, int>(a[i - 1] + 1, 0)) - c;
    if (L == second + 1 || c[L].first > a[i])
      f[i][0] = f[i][1] = f[i - 1][0];
    else {
      f[i][0] = f[i - 1][0] + a[i] - c[L].second;
      f[i][1] = f[i - 1][0] + 2 * (a[i] - c[L].second);
      f[i][0] = min(f[i][0], f[i - 1][1] + pr[i][0]);
      f[i][1] = min(f[i][1], f[i - 1][1] + pr[i][1]);
    }
  }
  cout << f[n][1] << "\n";
}
int main() {
  std::ios_base::sync_with_stdio;
  cin >> t;
  while (t--) sol();
}
