#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
const long long maxn = 3e5 + 100;
std::vector<pll> seg[maxn * 4];
std::vector<long long> blocked(maxn);
void insert(pll a, int c = 1, int l = 0, int r = maxn) {
  if (a.first <= l && r <= a.second) {
    seg[c].push_back(a);
    return;
  }
  int m = (l + r) / 2;
  if (a.first < m) {
    insert(a, c * 2, l, m);
  }
  if (a.second > m) {
    insert(a, c * 2 + 1, m, r);
  }
}
std::vector<pll> ret;
void query(long long pt, int c = 1, int l = 0, int r = maxn) {
  for (int i = 0; i < ((int)(seg[c]).size()); i++) {
    if (blocked[seg[c][i].second]) {
      std::swap(seg[c].back(), seg[c][i]);
      seg[c].pop_back();
      --i;
      continue;
    }
    ret.push_back(seg[c][i]);
  }
  if (l == r - 1) {
    return;
  }
  int m = (l + r) / 2;
  if (pt < m)
    query(pt, c * 2, l, m);
  else
    query(pt, c * 2 + 1, m, r);
}
int main() {
  std::ios::sync_with_stdio(false);
  long long n;
  std::cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long to;
    std::cin >> to;
    insert({i - to, i + 1});
  }
  std::vector<long long> fall(n + 1);
  std::vector<std::vector<long long>> backwards_reach(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long slip_back;
    std::cin >> slip_back;
    fall[i] = slip_back;
    backwards_reach[i + slip_back].push_back(i);
  }
  backwards_reach[0].push_back(0);
  std::vector<long long> pred(n + 1, -1);
  std::queue<long long> q;
  q.push(0);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto& jump_dest : backwards_reach[cur]) {
      ret.clear();
      query(jump_dest);
      for (auto& p : ret) {
        pred[p.second - 1] = jump_dest;
        q.push(p.second - 1);
        blocked[p.second] = 1;
      }
    }
  }
  if (pred[n] == -1) {
    std::cout << -1 << std::endl;
  } else {
    std::vector<long long> output;
    while (n != 0) {
      n = pred[n];
      output.push_back(n);
      n += fall[n];
    }
    std::cout << ((int)(output).size()) << std::endl;
    for (auto& n : output) std::cout << n << " ";
    std::cout << std::endl;
  }
  return 0;
}
