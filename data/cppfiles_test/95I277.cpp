#include <bits/stdc++.h>
int n, s, suf[15];
long long base_10[20];
std::vector<int> ans;
inline bool operator<(const std::pair<int, int> &x,
                      const std::pair<int, int> &y) {
  return x.second == y.second ? x.first > y.first : x.second < y.second;
}
std::priority_queue<std::pair<int, int> > q;
inline void split(int x) {
  ans.push_back(x);
  s -= x;
  q.pop();
}
inline void solve() {
  ans.clear();
  while (!q.empty()) q.pop();
  scanf("%d%d", &s, &n);
  int m = 0, tmp = s;
  while (tmp) {
    if (tmp % 10) q.push(std::pair<int, int>(tmp % 10, m));
    ++m;
    tmp /= 10;
  }
  for (int i = 1; i < n; ++i) {
    int x = q.top().first, y = q.top().second;
    if (x == 1) {
      if (y == 0) {
        split(1);
        continue;
      }
      split(base_10[y - 1]);
      q.push(std::pair<int, int>(9, y - 1));
      continue;
    }
    split(base_10[y]);
    q.push(std::pair<int, int>(x - 1, y));
  }
  ans.push_back(s);
  for (auto c : ans) printf("%d ", c);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  base_10[0] = 1;
  for (int i = 1; i <= 9; ++i) base_10[i] = base_10[i - 1] * 10;
  while (t--) solve();
  return 0;
}
