#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
map<int, int> mx, my;
vector<int> v;
long long cal() {
  long long ans = 0;
  int sz = v.size();
  sort(v.begin(), v.end());
  int l = 0, r;
  while (l < sz) {
    r = l;
    while (r < sz - 1 && v[r + 1] == v[l]) r++;
    ans += 1ll * (r - l + 1) * (r - l) / 2;
    l = r + 1;
  }
  return ans;
}
struct point {
  int x;
  int y;
} px[N], py[N];
bool cmpx(point &u, point &v) { return u.x < v.x; }
bool cmpy(point &u, point &v) { return u.y < v.y; }
int read() {
  char c = getchar();
  int ans = 0;
  while (c == ' ' || c == '\n') c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cx = 0, cy = 0;
    long long ans = 0;
    mx.clear();
    my.clear();
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, x; i <= n; i++) {
      x = read();
      mx[x] = 1;
    }
    for (int i = 1, y; i <= m; i++) {
      y = read();
      my[y] = 1;
    }
    for (int i = 1, x, y; i <= k; i++) {
      x = read();
      y = read();
      if (mx.count(x) && my.count(y)) continue;
      if (mx.count(x))
        py[++cy].x = x, py[cy].y = y;
      else
        px[++cx].x = x, px[cx].y = y;
    }
    sort(px + 1, px + cx + 1, cmpx);
    sort(py + 1, py + cy + 1, cmpy);
    map<int, int>::iterator P = mx.begin();
    int L = 1, R;
    while (P != mx.end()) {
      v.clear();
      v.push_back(px[L].y);
      int l = P->first;
      P++;
      int r = P->first;
      if (P == mx.end()) break;
      if (r < px[L].x) continue;
      R = L;
      while (R < cx && px[R + 1].x < r) R++, v.push_back(px[R].y);
      ans += 1LL * (R - L + 1) * (R - L) / 2 - cal();
      L = R + 1;
    }
    L = 1;
    P = my.begin();
    while (P != my.end()) {
      v.clear();
      v.push_back(py[L].x);
      int l = P->first;
      P++;
      int r = P->first;
      if (P == my.end()) break;
      if (r < py[L].y) continue;
      R = L;
      while (R < cy && py[R + 1].y < r) R++, v.push_back(py[R].x);
      ans += 1LL * (R - L + 1) * (R - L) / 2 - cal();
      L = R + 1;
    }
    cout << ans << endl;
  }
}
