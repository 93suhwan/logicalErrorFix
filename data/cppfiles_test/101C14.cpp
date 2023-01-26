#include <bits/stdc++.h>
using namespace std;
int N, M, K;
unordered_set<int> ver, hor;
vector<pair<pair<int, int>, bool>> vp, hp;
int main() {
  ios_base::sync_with_stdio(false);
  int TC;
  cin >> TC;
  while (TC--) {
    cin >> N >> M >> K;
    ver.clear();
    hor.clear();
    vp.clear();
    hp.clear();
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      ver.insert(x);
      hp.push_back({{x, 0}, false});
    }
    for (int i = 0; i < M; i++) {
      int y;
      cin >> y;
      hor.insert(y);
      vp.push_back({{y, 0}, false});
    }
    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      if (ver.count(x) && !hor.count(y)) {
        vp.push_back({{y, x}, true});
      } else if (!ver.count(x) && hor.count(y)) {
        hp.push_back({{x, y}, true});
      }
    }
    sort(vp.begin(), vp.end());
    sort(hp.begin(), hp.end());
    int cnt = 0;
    long long ans = 0;
    map<int, int> seen;
    for (auto e : vp) {
      if (e.second) {
        cnt++;
        seen[e.first.second]++;
        ans -= seen[e.first.second] - 1;
      } else {
        ans += (long long)cnt * (cnt - 1) / 2;
        seen.clear();
        cnt = 0;
      }
    }
    ans += (long long)cnt * (cnt - 1) / 2;
    cnt = 0;
    seen.clear();
    for (auto e : hp) {
      if (e.second) {
        cnt++;
        seen[e.first.second]++;
        ans -= seen[e.first.second] - 1;
      } else {
        ans += (long long)cnt * (cnt - 1) / 2;
        seen.clear();
        cnt = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
