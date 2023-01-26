#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto solve = [&]() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < M; i++) {
      int p, l, r;
      cin >> p >> l >> r;
      p--, r++;
      events.emplace_back(l, 1, p);
      events.emplace_back(r, 0, p);
    }
    sort(events.begin(), events.end());
    map<int, int> cnt;
    vector<pii> edges;
    for (auto [x, op, i] : events) {
      if (op == 1) {
        auto it = cnt.lower_bound(i);
        if (it == cnt.end() || it->first != i) {
          if (it != cnt.begin()) {
            edges.emplace_back(prev(it)->first, i);
          }
          if (it != cnt.end()) {
            edges.emplace_back(i, it->first);
          }
        }
        cnt[i]++;
      } else {
        auto it = cnt.find(i);
        it->second--;
        if (it != cnt.begin() && next(it) != cnt.end()) {
          edges.emplace_back(prev(it)->first, next(it)->first);
        }
        if (it->second == 0) {
          cnt.erase(it);
        }
      }
    }
    sort(edges.begin(), edges.end());
    vector<int> dp(N, 1), p(N, -1);
    for (auto [u, v] : edges) {
      if (dp[v] < dp[u] + 1) {
        dp[v] = dp[u] + 1;
        p[v] = u;
      }
    }
    vector<int> keep(N);
    int pnt = max_element(dp.begin(), dp.end()) - dp.begin();
    while (pnt >= 0) {
      keep[pnt] = 1;
      pnt = p[pnt];
    }
    vector<int> seq;
    for (int i = 0; i < N; i++) {
      if (!keep[i]) {
        seq.push_back(i);
      }
    }
    cout << int(seq.size()) << '\n';
    ;
    for (int i = 0; i < int(seq.size()); i++) {
      cout << seq[i] + 1 << " \n"[i == int(seq.size()) - 1];
    }
  };
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
