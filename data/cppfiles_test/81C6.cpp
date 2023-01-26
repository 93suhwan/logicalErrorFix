#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node &a) const {
    if (max(x, y) != max(a.x, a.y)) return max(x, y) < max(a.x, a.y);
    return min(x, y) < min(a.x, a.y);
  }
};
node st[500000 + 1];
int n, d, cnt;
int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) cin >> st[i].x >> st[i].y;
  sort(st + 1, st + n + 1);
  for (int i = 1; i <= n; ++i)
    if (st[i].x >= d) cnt++, d = max(d, st[i].y);
  cout << cnt << endl;
  return 0;
}
