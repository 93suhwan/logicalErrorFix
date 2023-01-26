#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node &a) const { return max(x, a.x) < max(y, a.y); }
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
