#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Grader {
  int u1, v1, u2, v2;
  Grader() {
    u1 = 2, v1 = 3;
    u2 = 4, v2 = 5;
  }
  int ask(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    int rs;
    cin >> rs;
    return rs;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Grader grader = Grader();
  int l = 1, r = INF, x, y;
  int tmp = grader.ask(1, 1);
  while (l <= r) {
    int mid = (l + r) / 2;
    if (grader.ask(mid, 1) + mid - 1 == tmp) {
      x = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  y = tmp + 2 - x;
  int xx = INF - grader.ask(INF, y);
  int yy = INF - grader.ask(xx, INF);
  cout << "! " << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
}
