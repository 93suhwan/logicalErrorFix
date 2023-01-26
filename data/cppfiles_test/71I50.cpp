#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, id;
  node() { x = y = id = 0; }
  node(int _x, int _y, int _id) {
    x = _x;
    y = _y;
    id = _id;
  }
  bool operator<(const node &a) const {
    if (x != a.x) return x < a.x;
    if (y != a.y) return y < a.y;
    return id < a.id;
  }
};
int n, k;
node a[200005];
bool sameline(int i, int j, int k) {
  if (a[i].x == a[j].x) return a[i].x == a[k].x;
  if (a[i].y == a[j].y) return a[i].y == a[k].y;
  return (long long)(a[i].x - a[j].x) * (a[i].y - a[k].y) ==
         (long long)(a[i].x - a[k].x) * (a[i].y - a[j].y);
}
double dis(int i, int j) {
  return sqrt((long long)(a[i].x - a[j].x) * (a[i].x - a[j].x) +
              (long long)(a[i].y - a[j].y) * (a[i].y - a[j].y));
}
bool test() {
  {
    int p = -1;
    for (int i = 3; i <= n; i++) {
      if (!sameline(1, 2, i)) {
        if (p != -1) return false;
        p = i;
      }
    }
    swap(a[p], a[1]);
    sort(a + 2, a + n + 1);
  }
  cout << fixed << setprecision(10);
  if (a[1].id == k) {
    cout << min(dis(1, 2), dis(1, n)) + dis(2, n) << '\n';
    return true;
  }
  int s = 2;
  while (a[s].id != k) {
    s++;
  }
  cout << min(s == n ? 1e9
                     : dis(s, 2) + dis(2, 1) + dis(1, s + 1) + dis(s + 1, n),
              s == 1 ? 1e9
                     : dis(s, n) + dis(n, 1) + dis(1, s - 1) + dis(s - 1, 2))
       << '\n';
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  while (!test()) {
    shuffle(a + 1, a + n + 1, rng);
  }
  return 0;
}
