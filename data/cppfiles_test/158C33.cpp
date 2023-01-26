#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 + 10, maxm = 1e4 + 10;
int a[maxn], mat[maxn][maxm], tmp[maxm], cnt[2 * maxn];
int n, m;
long long q;
bool ok;
long long f(int x) {
  long long res = 0;
  for (int i = 0; i < n; i++) {
    bool c = (1 << i) & x;
    if (c)
      res -= a[i];
    else
      res += a[i];
    for (int j = 1; j <= m; j++) {
      if (mat[i][j]) {
        if (c) {
          tmp[j]++;
        } else {
          tmp[j]--;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cnt[n + tmp[i]]++;
  }
  int w = m;
  for (int i = 2 * n; i >= 0; i--) {
    for (int j = 0; j < cnt[i]; j++) {
      res += 1LL * w * (i - n);
      w--;
    }
  }
  if (res == q) {
    ok = true;
    vector<pair<int, int>> v;
    for (int i = 1; i <= m; i++) {
      v.push_back({tmp[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
      tmp[v[i].second] = i + 1;
    }
    for (int i = 1; i <= m; i++) cout << tmp[i] << " ";
    cout << "\n";
  }
  memset(tmp, 0, sizeof(tmp));
  memset(cnt, 0, sizeof(cnt));
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == '1') mat[i][j] = 1;
      }
    }
    long long ans = -1e18;
    ok = false;
    q = -1e18;
    for (int i = 0; i < (1 << n); i++) {
      ans = max(ans, f(i));
    }
    q = ans;
    for (int i = 0; i < (1 << n); i++) {
      f(i);
      if (ok) break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        mat[i][j] = 0;
      }
    }
  }
  return 0;
}
