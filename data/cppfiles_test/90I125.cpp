#include <bits/stdc++.h>
constexpr long long INF = 1000000666ll * 1000000000ll;
constexpr int MAGIC = 1000000666;
void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> A(n);
  for (int i = 0; i < (n); ++i) std::cin >> A[i];
  std::sort(A.begin(), A.end());
  std::vector<std::pair<int, int> > B(m);
  for (int i = 0; i < (m); ++i) {
    std::cin >> B[i].first >> B[i].second;
  }
  std::sort(B.begin(), B.end());
  std::set<std::pair<int, int> > set;
  std::vector<std::pair<int, int> > evs;
  for (int i = 0; i < (m); ++i) {
    evs.push_back(std::make_pair(B[i].first, -i - 1));
    evs.push_back(std::make_pair(B[i].second, i + 1));
  }
  for (int i = 0; i < (n); ++i) evs.push_back(std::make_pair(A[i], 0));
  std::sort(evs.begin(), evs.end());
  std::vector<bool> dead(m);
  for (auto& ev : (evs)) {
    int x = ev.first;
    int y = ev.second;
    if (y < 0) {
      y *= -1;
      y--;
      set.insert(std::make_pair(x, y));
    } else if (y > 0) {
      y--;
      auto it = set.lower_bound(std::make_pair(B[y].first + 1, -1));
      if (it != set.begin()) {
        --it;
        while (true) {
          if (it == set.begin()) {
            if (it->second != y) dead[it->second] = true;
            set.erase(it);
            break;
          }
          auto next = std::prev(it);
          if (it->second != y) dead[it->second] = true;
          set.erase(it);
          it = next;
        }
      }
    } else {
    }
  }
  std::vector<std::pair<int, int> > C;
  for (int i = 0; i < (m); ++i) {
    if (!dead[i]) C.push_back(B[i]);
  }
  for (int i = 0; i < (((int)(C).size()) - 1); ++i) {
    assert(C[i].first < C[i + 1].first);
    assert(C[i].second <= C[i + 1].second);
  }
  if (((int)(C).size()) == 0) {
    std::cout << 0 << "\n";
    return;
  }
  std::map<int, long long> cost;
  for (auto& pr : (C)) cost[pr.first] = INF;
  cost[MAGIC] = 0;
  for (int i = 0; i < (n); ++i) {
    std::vector<int> prev;
    auto pocz = (i == 0 ? C.begin()
                        : std::lower_bound(C.begin(), C.end(),
                                           std::make_pair(A[i - 1], -MAGIC)));
    auto kon =
        std::lower_bound(C.begin(), C.end(), std::make_pair(A[i], -MAGIC));
    while (pocz < kon) {
      prev.push_back(std::distance(pocz, C.begin()));
      pocz++;
    }
    std::vector<int> next;
    pocz = std::lower_bound(C.begin(), C.end(), std::make_pair(A[i], -MAGIC));
    kon = (i == n - 1 ? C.end()
                      : std::lower_bound(C.begin(), C.end(),
                                         std::make_pair(A[i + 1], -MAGIC)));
    while (pocz < kon) {
      next.push_back(std::distance(pocz, C.begin()));
      pocz++;
    }
    long long best1 = INF;
    long long best2 = INF;
    for (int x = 0; x < (((int)(prev).size())); ++x) {
      int musze;
      if (x == ((int)(prev).size()) - 1) {
        musze = 0;
      } else {
        musze = A[i] - C[prev[x + 1]].second;
      }
      best2 = std::min(best2, cost[C[prev[x]].first] + 2ll * musze);
      best1 = std::min(best1, cost[C[prev[x]].first] + musze);
    }
    if (((int)(prev).size())) {
      int musze = A[i] - C[prev[0]].second;
      best2 = std::min(best2, cost[MAGIC] + 2ll * musze);
      best1 = std::min(best1, cost[MAGIC] + musze);
    } else {
      best1 = cost[MAGIC];
      best2 = cost[MAGIC];
    }
    cost[MAGIC] = best1;
    for (int x = 0; x < (((int)(next).size())); ++x) {
      int musze = C[next[x]].first - A[i];
      cost[next[x]] = std::min(best2 + musze, best1 + 2ll * musze);
    }
  }
  std::cout << cost[C.back().first] << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
    std::cout << std::flush;
  }
  return 0;
}
