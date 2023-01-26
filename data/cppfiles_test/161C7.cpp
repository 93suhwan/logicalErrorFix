#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1000000007, mod2 = 998244353;
long long mn = LLONG_MAX;
long long mx = LLONG_MIN;
long long mod;
int ans[10002][1002], ck[1002][1002], tk[1002];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc, o;
  cin >> tc;
  for (o = 1; o <= tc; o++) {
    int n, l, r, a, b, c, i, j, k;
    cin >> n;
    vector<pair<int, int> > vct;
    for (i = 1; i <= n; i++) {
      cin >> l >> r;
      ck[l][r] = o;
      vct.push_back({l, r});
    }
    queue<pair<int, int> > qu;
    pair<int, int> pp, qq;
    pp = {1, n};
    qu.push(pp);
    while (!qu.empty()) {
      qq = qu.front();
      qu.pop();
      l = qq.first;
      r = qq.second;
      if (l == r) {
        ans[l][r] = l;
      } else {
        for (i = l; i <= r; i++) {
          if (i == l) {
            if (ck[i + 1][r] == o) {
              ans[l][r] = i;
              qu.push({i + 1, r});
              break;
            }
          } else if (i == r) {
            if (ck[l][i - 1] == o) {
              ans[l][r] = i;
              qu.push({l, i - 1});
              break;
            }
          } else {
            if (ck[l][i - 1] == o && ck[i + 1][r] == o) {
              ans[l][r] = i;
              qu.push({l, i - 1});
              qu.push({i + 1, r});
              break;
            }
          }
        }
      }
    }
    for (i = 0; i < n; i++) {
      l = vct[i].first;
      r = vct[i].second;
      cout << l << " " << r << " " << ans[l][r];
      cout << "\n";
    }
    cout << "\n";
    vct.clear();
  }
  return 0;
}
