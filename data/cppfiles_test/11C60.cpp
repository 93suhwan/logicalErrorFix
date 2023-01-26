#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  char tmp = getchar();
  int ans = 0, flag = 1;
  while (!isdigit(tmp)) {
    if (tmp == '-') flag = -1;
    tmp = getchar();
  }
  while (isdigit(tmp)) {
    ans = ans * 10 + tmp - '0';
    tmp = getchar();
  }
  return ans * flag;
}
inline void in(int &x) { x = gi(); }
inline void in2(int &x, int &y) { in(x), in(y); }
inline void in3(int &x, int &y, int &z) { in(x), in(y), in(z); }
inline void in4(int &x, int &y, int &z, int &a) { in3(x, y, z), in(a); }
inline void smax(int &x, int y) { x = max(x, y); }
inline void smin(int &x, int y) { x = min(x, y); }
int lowbit(int x) { return x & -x; }
const int N = 1002000;
int C[N], n, maxx;
void Add(int x, int v) {
  while (x <= maxx) {
    smax(C[x], v);
    x += lowbit(x);
  }
}
int Query(int x) {
  int ans = 0;
  while (x) {
    smax(ans, C[x]);
    x -= lowbit(x);
  }
  return ans;
}
struct Nod {
  int x, y;
} Node[N];
bool cmp(Nod a, Nod b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}
signed main() {
  int n = gi();
  for (int i = (int)(1); i <= (int)(n); ++i) {
    Node[i].x = gi();
    Node[i].y = i - Node[i].x;
    smax(maxx, Node[i].x);
  }
  sort(Node + 1, Node + n + 1, cmp);
  int ans = 0;
  for (int i = (int)(1); i <= (int)(n); ++i) {
    if (Node[i].y < 0) continue;
    int g = Query(Node[i].x - 1);
    Add(Node[i].x, g + 1);
    smax(ans, g + 1);
  }
  printf("%d\n", ans);
  return 0;
}
