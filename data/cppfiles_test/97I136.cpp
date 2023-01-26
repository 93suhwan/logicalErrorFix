#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2000010;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
void read(int &a) { scanf("%d", &a); }
void read(long long &a) { scanf("%lld", &a); }
void read(double &a) { scanf("%lf", &a); }
void write(int &a) { printf("%d ", a); }
void write(long long &a) { printf("%lld ", a); }
void write(double &a) { printf("%.10lf ", a); }
void I(){};
template <class T, class... A>
void I(T &a, A &...x) {
  read(a);
  I(x...);
}
void O(){};
template <class T, class... A>
void O(T &a, A &...x) {
  write(a);
  O(x...);
}
int n, m;
char s[510][510];
int id[510][510];
int ans[510][510];
vector<int> G[510 * 510];
int color[510 * 510];
int main() {
  I(n, m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.') continue;
      int cnt = 0;
      for (int fx = -1; fx <= 1; fx++)
        for (int fy = -1; fy <= 1; fy++)
          if (fx * fy == 0) {
            cnt += (s[i + fx][j + fy] == '.');
          }
      if (cnt % 2) {
        return 0 * puts("NO");
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') continue;
      if (id[i][j] == 0) {
        id[i][j] = ++cnt;
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int fx = -1; fx <= 1; fx++)
            for (int fy = -1; fy <= 1; fy++) {
              if (fx * fy) continue;
              if (x + fx < 1 || x + fx > n) continue;
              if (y + fy < 1 || y + fy > m) continue;
              if (s[x + fx][y + fy] == 'X') continue;
              if (id[x + fx][y + fy] == 0) {
                id[x + fx][y + fy] = cnt;
                q.push(make_pair(x + fx, y + fy));
              }
            }
        }
      }
    }
  }
  auto addl = [&](int x, int y) {
    G[x].push_back(y);
    G[y].push_back(x);
    return 0;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        if (s[i - 1][j] != 'X' && s[i + 1][j] != 'X') {
          if (id[i - 1][j] != id[i + 1][j]) {
            addl(id[i - 1][j], id[i + 1][j]);
          }
        }
        if (s[i][j - 1] != 'X' && s[i][j + 1] != 'X') {
          if (id[i][j - 1] != id[i][j + 1]) {
            addl(id[i][j - 1], id[i][j + 1]);
          }
        }
      }
    }
  }
  memset(color, 0, sizeof(color));
  for (int i = 1; i <= cnt; i++) {
    if (color[i] == 0) {
      queue<int> q;
      color[i] = 1;
      q.push(i);
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto x : G[now]) {
          if (color[x] == 0) {
            color[x] = 3 - color[now];
            q.push(x);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (id[i][j] == 0) continue;
      if (color[id[i][j]] == 1) {
        if (j % 2 == 0) {
          ans[i][j] = 1;
        } else {
          ans[i][j] = 4;
        }
      } else {
        if (j % 2 == 0) {
          ans[i][j] = 4;
        } else {
          ans[i][j] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        for (int fx = -1; fx <= 1; fx++)
          for (int fy = -1; fy <= 1; fy++)
            if (fx * fy == 0 && fx != fy) {
              if (s[i + fx][j + fy] == '.') {
                ans[i][j] += ans[i + fx][j + fy];
              }
            }
      }
    }
  }
  if (n == 31 && m == 23) {
    cout << ans[15][4] << endl;
  }
  puts("YES");
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
  return 0;
}
