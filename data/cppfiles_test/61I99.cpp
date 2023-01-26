#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int nmax = 2e5 + 5;
int t, n, a[nmax], b[nmax], f[nmax], L[nmax], R[nmax], d[nmax];
long long ans;
vector<int> v1[nmax], v2[nmax];
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      v1[i].clear();
      v2[i].clear();
      f[i] = 0;
      d[i] = 0;
    }
    R[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      f[b[i]]++;
      v1[a[i]].emplace_back(b[i]);
      v2[b[i]].emplace_back(a[i]);
    }
    for (int i = 1; i <= n; i++) L[i] = L[i - 1] + v2[i].size();
    for (int i = n; i >= 1; i--) R[i] = R[i + 1] + v2[i].size();
    for (int i = 2; i < n; i++)
      ans = ans + 1ll * v2[i].size() * L[i - 1] * R[i + 1];
    for (int i = 1; i <= n; i++) L[i] = L[i - 1] + v1[i].size();
    for (int i = n; i >= 1; i--) R[i] = R[i + 1] + v1[i].size();
    for (int i = 2; i < n; i++)
      ans = ans + 1ll * v1[i].size() * L[i - 1] * R[i + 1];
    for (int i = 1; i <= n; i++) sort(v1[i].begin(), v1[i].end());
    for (int i = 1; i <= n; i++)
      if (v1[i].size() > 0) {
        int dem = 1;
        for (int j = 1; j < v1[i].size(); j++)
          if (v1[i][j] != v1[i][j - 1]) {
            int x = v1[i][j - 1];
            ans = ans - 1ll * dem * (L[i - 1] - d[x]) *
                            (n - L[i] - (f[x] - d[x] - dem));
            dem = 1;
          } else
            dem++;
        int x = v1[i][v1[i].size() - 1];
        ans = ans -
              1ll * dem * (L[i - 1] - d[x]) * (n - L[i] - (f[x] - d[x] - dem));
        for (auto p : v1[i]) d[p]++;
      }
    for (int i = 1; i <= n; i++) d[i] = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++)
      if (v1[i].size() > 0) {
        int dem = 1;
        for (int j = 1; j < v1[i].size(); j++)
          if (v1[i][j] != v1[i][j - 1]) {
            int x = v1[i][j - 1];
            res = res - 1ll * dem * d[x];
            dem = 1;
          } else
            dem++;
        int x = v1[i][v1[i].size() - 1];
        res = res - 1ll * dem * d[x];
        ans = ans + 1ll * v1[i].size() * res;
        dem = 1;
        for (int j = 1; j < v1[i].size(); j++)
          if (v1[i][j] != v1[i][j - 1]) {
            int x = v1[i][j - 1];
            res = res + 1ll * dem * (f[x] - d[x] - dem);
            dem = 1;
          } else
            dem++;
        x = v1[i][v1[i].size() - 1];
        res = res + 1ll * dem * (f[x] - d[x] - dem);
        for (auto p : v1[i]) d[p]++;
      }
    for (int i = 1; i <= n; i++) d[i] = 0;
    for (int i = 1; i <= n; i++)
      if (v1[i].size() > 0) {
        int dem = 1;
        for (int j = 1; j < v1[i].size(); j++)
          if (v1[i][j] != v1[i][j - 1]) {
            int x = v1[i][j - 1];
            ans = ans - 1ll * d[x] * (f[x] - d[x] - dem);
            dem = 1;
          } else
            dem++;
        int x = v1[i][v1[i].size() - 1];
        ans = ans - 1ll * d[x] * (f[x] - d[x] - dem);
      }
    cout << ans << '\n';
  }
}
