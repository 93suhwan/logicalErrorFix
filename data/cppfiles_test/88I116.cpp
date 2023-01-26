#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<long long> V[205];
vector<long long> Vt[205];
long long dp[205][205];
long long ans;
void init() {}
void solve() {
  int n, m;
  cin >> n >> m;
  int tot = n * m;
  vector<std::pair<int, int> > a(tot + 1);
  for (int i = 1; i <= tot; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin() + 1, a.end(),
       [&](std::pair<int, int> x, std::pair<int, int> y) {
         return x.first < y.first ||
                (x.first == y.first && x.second > y.second);
       });
  for (int i = 1; i <= tot; i++) {
    int j = i;
    while (j <= tot && a[j].first == a[i].first) {
      ++j;
    }
    --j;
    int lnum = m - (i % m) + 1;
    if (lnum > m) lnum -= m;
    if (i + lnum - 1 < j) {
      int rnum = j % m;
      if (rnum == 0) rnum = m;
      vector<std::pair<int, int> > tmpl(lnum + 1);
      vector<std::pair<int, int> > tmpr(rnum + 1);
      if (lnum <= rnum) {
        for (int k = i; k < i + lnum; ++k) {
          tmpl[k - i + 1] = a[k];
          a[k] = a[j - lnum + k - i + 1];
        }
        for (int k = j - lnum; k > j - rnum; --k) {
          a[k + lnum] = a[k];
        }
        for (int k = 1; k <= lnum; ++k) {
          a[j - rnum + k] = tmpl[k];
        }
      } else {
        for (int k = 1; k <= rnum; ++k) {
          tmpr[k] = a[j - rnum + k];
          a[j - rnum + k] = a[i + k - 1];
        }
        for (int k = i + rnum; k < i + lnum; ++k) {
          a[k - rnum] = a[k];
        }
        for (int k = i + lnum - rnum; k < i + lnum; ++k) {
          a[k] = tmpr[k - i - lnum + rnum + 1];
        }
      }
    }
    i = j;
  }
  int cnt = 0;
  for (int i = 1; i <= tot; i += m) {
    int l = i, r = i + m - 1;
    for (int j = l; j <= r; ++j) {
      for (int k = l; k < j; ++k) {
        if (a[k].second < a[j].second) ++cnt;
      }
    }
  }
  cout << cnt << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
