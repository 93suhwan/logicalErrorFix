#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, INF = 1000000009;
int n, m;
int a[N];
vector<pair<int, int> > b;
bool so(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second < b.second) return true;
  if (a.second > b.second) return false;
  return a.first > b.first;
}
void solv() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  b.clear();
  {
    set<pair<int, int> > ss;
    for (int i = 0; i < m; ++i) {
      int l, r;
      cin >> l >> r;
      int j = lower_bound(a + 1, a + n + 1, l) - a;
      if (1 <= j && j <= n && l <= a[j] && a[j] <= r) continue;
      if (ss.find(make_pair(l, r)) != ss.end()) continue;
      ss.insert(make_pair(l, r));
      b.push_back(make_pair(l, r));
    }
    sort((b).begin(), (b).end(), so);
    vector<pair<int, int> > bb;
    int maxu = -INF;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i].first > maxu) {
        bb.push_back(b[i]);
        maxu = b[i].first;
      }
    }
    b = bb;
  }
  a[n + 1] = INF;
  vector<pair<int, int> > l;
  vector<pair<int, int> > r;
  int j = 0;
  while (j < ((int)(b).size()) && b[j].second < a[1]) {
    r.push_back(b[j++]);
  }
  vector<long long> dp0;
  dp0.push_back(0);
  for (int i = 0; i < r.size(); ++i) dp0.push_back(INF * 1LL * INF);
  for (int i = 1; i <= n; ++i) {
    swap(l, r);
    r.clear();
    while (j < ((int)(b).size()) && b[j].second < a[i + 1]) {
      r.push_back(b[j++]);
    }
    long long min1 = INF * 1LL * INF;
    for (int i = 0; i < ((int)(l).size()); ++i) {
      long long t = -l[i].second + dp0[i];
      min1 = min(min1, t);
    }
    long long min2 = INF * 1LL * INF;
    for (int i = 0; i < ((int)(l).size()); ++i) {
      long long t = -l[i].second - l[i].second + dp0[i];
      min2 = min(min2, t);
    }
    vector<long long> dp1;
    for (int j = 0; j <= r.size(); ++j) {
      if (j == 0) {
        dp1.push_back(dp0.back());
        for (int k = 0; k < ((int)(l).size()); ++k) {
          dp1.back() = min(dp1.back(), a[i] - l[k].second + dp0[k]);
        }
      } else {
        dp1.push_back(dp0.back() + r[j - 1].first - a[i]);
        dp1.back() =
            min(dp1.back(), r[j - 1].first + r[j - 1].first - a[i] + min1);
        dp1.back() = min(dp1.back(), r[j - 1].first + a[i] + min2);
      }
    }
    dp0 = dp1;
  }
  cout << dp0.back() << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solv();
  return 0;
}
