#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long INF = 2e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long m = n * 2;
    vector<bool> used(n * 2 + 5, false);
    vector<pair<long long, long long>> seg(k);
    for (long long i = 0; i < k; i++) {
      cin >> seg[i].first >> seg[i].second;
      if (seg[i].first > seg[i].second) swap(seg[i].first, seg[i].second);
      used[seg[i].first] = true;
      used[seg[i].second] = true;
    }
    vector<long long> x;
    for (long long i = 1; i <= m; i++) {
      if (!used[i]) x.push_back(i);
    }
    for (long long i = 0; i < x.size() / 2; i++) {
      seg.push_back({x[i], x[i + x.size() / 2]});
    }
    long long ret = 0;
    for (long long i = 0; i < seg.size(); i++) {
      for (long long j = i + 1; j < seg.size(); j++) {
        long long l1 = seg[i].first, r1 = seg[i].second;
        long long l2 = seg[j].first, r2 = seg[j].second;
        if (l1 < l2 && r2 < r1) continue;
        if (l2 < l1 && r1 < r2) continue;
        if (l1 > r2 || l2 > r1) continue;
        if (r2 < l1 || r1 < l2) continue;
        ret++;
      }
    }
    cout << ret << "\n";
  }
  return 0;
}
