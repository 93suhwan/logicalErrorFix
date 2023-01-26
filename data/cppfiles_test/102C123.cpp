#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 400010;
int h[N], e[N * 2], ne[N * 2], idx;
int gcd(int a, int b) { return b ? (gcd(b, a % b)) : a; }
map<int, int> ma;
map<int, int> mb;
vector<int> b;
inline int read() {
  int x = 0;
  bool f = false;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    f |= (ch == 45);
    ch = getchar();
  }
  while (ch > 47 && ch < 58)
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? ~x + 1 : x;
}
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}
void test_case() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int minx = 0, miny = 0, maxx = 0, maxy = 0;
  int x = 0, y = 0;
  for (char c : s) {
    if (c == 'L') y -= 1;
    if (c == 'R') y += 1;
    if (c == 'U') x -= 1;
    if (c == 'D') x += 1;
    if (x > maxx) {
      if (x - minx < n)
        maxx = x;
      else
        break;
    }
    if (x < minx) {
      if (maxx - x < n)
        minx = x;
      else
        break;
    }
    if (y > maxy) {
      if (y - miny < m)
        maxy = y;
      else
        break;
    }
    if (y < miny) {
      if (maxy - y < m)
        miny = y;
      else
        break;
    }
  }
  cout << 1 - minx << " " << 1 - miny << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    test_case();
  }
}
