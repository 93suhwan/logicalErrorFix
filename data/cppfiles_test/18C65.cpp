#include <bits/stdc++.h>
using namespace std;
deque<int> d;
int _, n, l, ans, cnt, i, x, dis[1000001];
int main() {
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &n, &l);
    ans = cnt = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &x);
      dis[i] = x * 1e9;
      if (x == 0) d.push_back(i), cnt++;
    }
    while (!d.empty()) {
      x = d.front();
      d.pop_front();
      if (dis[(x + l) % n] == 1e9)
        dis[(x + l) % n] = dis[x] + 1, ans = max(ans, dis[x] + 1), cnt++,
                      d.push_back((x + l) % n);
    }
    if (cnt == n)
      printf("%d\n", ans);
    else
      puts("-1");
  }
}
