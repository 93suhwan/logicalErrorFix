#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
const long long maxn = 3e5 + 100;
std::set<pll> seg[maxn * 4];
void insert(pll a, int c = 1, int l = 0, int r = maxn) {
  if (a.first <= l && r <= a.second) {
    seg[c].insert(a);
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
void remove(pll a, int c = 1, int l = 0, int r = maxn) {
  if (a.first <= l && r <= a.second) {
    seg[c].erase(a);
    return;
  }
  int m = (l + r) / 2;
  if (a.first < m) {
    remove(a, c * 2, l, m);
  }
  if (a.second > m) {
    remove(a, c * 2 + 1, m, r);
  }
}
std::vector<pll> ret;
void query(long long pt, int c = 1, int l = 0, int r = maxn) {
  for (auto& x : seg[c]) ret.push_back(x);
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
      }
      for (auto& p : ret) remove(p);
    }
  }
  if (pred[n] == -1) {
    std::cout << -1 << std::endl;
  } else {
    while (n != 0) {
      n = pred[n];
      std::cout << n << " ";
      n += fall[n];
    }
    std::cout << std::endl;
  }
  return 0;
}
