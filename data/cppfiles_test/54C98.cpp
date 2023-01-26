#include <bits/stdc++.h>
using namespace std;
const bool read_file = false;
const char fi[] = "XX.INP";
const char fo[] = "XX.OUT";
void set_up() {
  if (read_file) {
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
  }
  cin.clear();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void just_do_it();
int main() {
  set_up();
  just_do_it();
}
struct msg {
  int x;
  int y;
  int f;
  int id;
};
int flip(int k) {
  int k1, k2;
  k1 = k / 2 * 2;
  k2 = k1 + 1;
  if (k == k1) {
    return k2;
  } else {
    return k1;
  }
}
void query() {
  int n, m, x, y, f, r, cx, cy, pa, pb, res;
  string s;
  cin >> n >> m;
  bool fm[m];
  int st[n];
  fill_n(fm, m, false);
  fill_n(st, n, -1);
  vector<msg> a[n];
  msg p[m];
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> s;
    x--;
    y--;
    if (s == "imposter") {
      f = 0;
    } else {
      f = 1;
    }
    p[i] = {x, y, f, i};
    a[x].push_back({x, y, f, i});
    a[y].push_back({y, x, f, i});
  }
  r = 0;
  res = n;
  for (int i = 0; i < m; i++) {
    if (fm[i]) {
      continue;
    }
    fm[i] = true;
    x = p[i].x;
    y = p[i].y;
    f = p[i].f;
    if (st[x] == -1 && st[y] == -1) {
      st[x] = r;
      pa = 0;
      pb = 0;
      if (f == 0) {
        st[y] = flip(st[x]);
      } else {
        st[y] = st[x];
      }
      deque<int> q = {x, y};
      while (!q.empty()) {
        cx = q.front();
        if (st[cx] == r) {
          pa++;
        } else {
          pb++;
        }
        res--;
        for (auto mp : a[cx]) {
          if (fm[mp.id]) {
            continue;
          }
          fm[mp.id] = true;
          cy = mp.y;
          f = mp.f;
          if (st[cy] == -1) {
            if (f == 0) {
              st[cy] = flip(st[cx]);
            } else {
              st[cy] = st[cx];
            }
            q.push_back(cy);
          } else {
            if (f == 0) {
              if (st[cy] != flip(st[cx])) {
                cout << -1 << endl;
                return;
              }
            }
            if (f == 1) {
              if (st[cy] != st[cx]) {
                cout << -1 << endl;
                return;
              }
            }
          }
        }
        q.pop_front();
      }
      res += max(pa, pb);
      r += 2;
    }
  }
  cout << res << endl;
  return;
}
void just_do_it() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    query();
  }
}
