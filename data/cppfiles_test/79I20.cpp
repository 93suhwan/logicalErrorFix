#include <bits/stdc++.h>
int n, from[300005], p[300005], dis[300005], a[300005], b[300005];
std::queue<int> que;
void work(int now) {
  if (now != n) work(from[now]), std::cout << p[now] << ' ';
}
void print(int now) {
  std::cout << dis[now] << std::endl;
  work(now);
  std::cout << 0 << std::endl;
  exit(0);
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  std::fill(from, from + 1 + n, -1);
  que.push(n);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    if (now - a[now] <= 0) print(now);
    for (int i = 0; i <= a[now]; ++i) {
      int tmp = now - i + b[now - i];
      if (!~from[tmp])
        dis[tmp] = dis[now] + 1, p[tmp] = now - i, from[tmp] = now,
        que.push(tmp);
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}
