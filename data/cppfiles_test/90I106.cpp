#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long inf = 1e9 + 228;
const long long INFLL = 1e18;
const long double eps = 1e-12;
const long double eps2 = 1e-9;
const long long mod2 = 998244353;
const long long dosz = 5e5;
const long long SZ = (1 << 18);
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> lol(n);
  for (long long &i : lol) cin >> i;
  lol.push_back(inf);
  sort(lol.begin(), lol.end());
  vector<pair<long long, long long> > kek;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    if (*lower_bound(lol.begin(), lol.end(), a) <= b) {
    } else {
      kek.push_back(make_pair(a, b));
    }
  }
  if (kek.empty()) {
    cout << 0 << '\n';
    return;
  }
  sort(kek.begin(), kek.end(), cmp);
  vector<pair<long long, long long> > nw;
  for (long long i = kek.size() - 1; i >= 0; i--) {
    if (nw.empty() || nw.back().second > kek[i].second) {
      nw.push_back(kek[i]);
    }
  }
  reverse(nw.begin(), nw.end());
  kek = nw;
  if (kek.empty()) {
    cout << 0 << '\n';
    return;
  }
  sort(kek.begin(), kek.end());
  vector<pair<long long, long long> > dp(n);
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      if (kek[0].second < lol[0]) {
        dp[i] =
            make_pair((lol[0] - kek[0].second), (lol[0] - kek[0].second) * 2);
      }
    } else {
      dp[i] = make_pair(INFLL, INFLL);
      long long pnt =
          lower_bound(kek.begin(), kek.end(), make_pair(lol[i - 1], 0ll)) -
          kek.begin();
      if (pnt >= kek.size() || kek[pnt].first > lol[i]) {
        dp[i] = make_pair(dp[i - 1].first, dp[i - 1].first);
      }
      long long pnt2 = pnt;
      while (pnt2 < kek.size() && kek[pnt2].second < lol[i]) {
        pnt2++;
      }
      pnt2--;
      if (pnt == pnt2) {
        dp[i].first = min(dp[i].first,
                          dp[i - 1].first + (kek[pnt].first - lol[i - 1]) * 2);
        dp[i].first =
            min(dp[i].first, dp[i - 1].second + (kek[pnt].first - lol[i - 1]));
        dp[i].first =
            min(dp[i].first, dp[i - 1].first + (lol[i] - kek[pnt].second));
        dp[i].first =
            min(dp[i].first, dp[i - 1].second + (lol[i] - kek[pnt].second));
        dp[i].second =
            min(dp[i].second, min(dp[i - 1].first, dp[i - 1].second) +
                                  (lol[i] - kek[pnt].second) * 2);
        dp[i].second = min(dp[i].second,
                           dp[i - 1].first + (kek[pnt].first - lol[i - 1]) * 2);
        dp[i].second =
            min(dp[i].second, dp[i - 1].second + (kek[pnt].first - lol[i - 1]));
      } else {
        for (long long j = pnt; j < pnt2; j++) {
          dp[i].first = min(dp[i].first, dp[i - 1].first +
                                             (kek[j].first - lol[i - 1]) * 2 +
                                             (lol[i] - kek[j + 1].second));
          dp[i].first =
              min(dp[i].first, dp[i - 1].second + (kek[j].first - lol[i - 1]) +
                                   (lol[i] - kek[j + 1].second));
          dp[i].second = min(dp[i].second,
                             dp[i - 1].first + (kek[j].first - lol[i - 1]) * 2 +
                                 (lol[i] - kek[j + 1].second) * 2);
          dp[i].second =
              min(dp[i].second, dp[i - 1].second + (kek[j].first - lol[i - 1]) +
                                    (lol[i] - kek[j + 1].second) * 2);
        }
        dp[i].first = min(dp[i].first,
                          dp[i - 1].first + (kek[pnt2].first - lol[i - 1]) * 2);
        dp[i].first =
            min(dp[i].first, dp[i - 1].second + (kek[pnt2].first - lol[i - 1]));
        dp[i].first =
            min(dp[i].first, dp[i - 1].first + (lol[i] - kek[pnt].second));
        dp[i].first =
            min(dp[i].first, dp[i - 1].second + (lol[i] - kek[pnt].second));
        dp[i].second =
            min(dp[i].second, min(dp[i - 1].first, dp[i - 1].second) +
                                  (lol[i] - kek[pnt].second) * 2);
        dp[i].second = min(
            dp[i].second, dp[i - 1].first + (kek[pnt2].first - lol[i - 1]) * 2);
        dp[i].second = min(dp[i].second,
                           dp[i - 1].second + (kek[pnt2].first - lol[i - 1]));
      }
    }
  }
  lol.pop_back();
  if (kek.back().second < lol.back()) {
    cout << min(dp.back().first, dp.back().second) << '\n';
  } else {
    cout << min(dp.back().first + (kek.back().first - lol.back()) * 2,
                dp.back().second + (kek.back().first - lol.back()))
         << '\n';
  }
}
signed main() {
  fast_io();
  srand(time(NULL));
  long long q = 1;
  cin >> q;
  while (q--) solve();
}
