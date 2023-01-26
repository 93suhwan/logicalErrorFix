#include <bits/stdc++.h>
using namespace std;
const long long INF64 = 1e18;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  sort(a.begin(), a.end());
  vector<pair<int, int>> cnt;
  for (auto it : a) {
    if (cnt.empty() || cnt.back().first != it) {
      cnt.push_back({it, 1});
    } else {
      ++cnt.back().second;
    }
  }
  vector<long long> prefsum, sufsum;
  vector<int> prefcnt, sufcnt;
  for (int i = 0; i < int(cnt.size()); ++i) {
    long long cursum = cnt[i].first * 1ll * cnt[i].second;
    int curcnt = cnt[i].second;
    if (prefsum.empty()) {
      prefsum.push_back(cursum);
      prefcnt.push_back(curcnt);
    } else {
      prefsum.push_back(prefsum.back() + cursum);
      prefcnt.push_back(prefcnt.back() + curcnt);
    }
  }
  for (int i = int(cnt.size()) - 1; i >= 0; --i) {
    long long cursum = cnt[i].first * 1ll * cnt[i].second;
    int curcnt = cnt[i].second;
    if (sufsum.empty()) {
      sufsum.push_back(cursum);
      sufcnt.push_back(curcnt);
    } else {
      sufsum.push_back(sufsum.back() + cursum);
      sufcnt.push_back(sufcnt.back() + curcnt);
    }
  }
  reverse(sufsum.begin(), sufsum.end());
  reverse(sufcnt.begin(), sufcnt.end());
  long long ans = INF64;
  for (int i = 0; i < int(cnt.size()); ++i) {
    int cur = max(0, k - cnt[i].second);
    int needl = 0;
    if (i > 0) needl = min(cur, prefcnt[i - 1]);
    int needr = max(0, cur - needl);
    long long res = 0;
    if (i > 0 && needl > 0) {
      res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
      res += needl;
    }
    if (i + 1 < int(cnt.size()) && needr > 0) {
      res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
      res += needr;
    }
    ans = min(ans, res);
    needr = 0;
    if (i + 1 < int(cnt.size())) needr = min(cur, sufcnt[i + 1]);
    needl = max(0, cur - needr);
    res = 0;
    if (i > 0 && needl > 0) {
      res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
      res += needl;
    }
    if (i + 1 < int(cnt.size()) && needr > 0) {
      res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
      res += needr;
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}
