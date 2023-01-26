#include <bits/stdc++.h>
using namespace std;
void judge() {}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int p1 = 1e9 + 7;
long long int p2 = 998244353;
struct segtree {
  vector<int> v;
  int n, n2;
  void init(int x) {
    n = x;
    int a = 1;
    while (a <= x) a *= 2;
    a *= 2;
    n2 = a;
    v.assign(n2, 0);
  }
  int return_max(int curr, int r2, int l, int r) {
    if (l == r) {
      return v[curr];
    }
    int mid = (r + l) / 2;
    if (r2 <= mid) return return_max(2 * curr + 1, r2, l, mid);
    return max(v[2 * curr + 1], return_max(2 * curr + 2, r2, mid + 1, r));
  }
  int return_max(int r) {
    if (r < 0) return 0;
    return return_max(0, r, 0, n - 1);
  }
  void update(int curr, int pos, int val, int l, int r) {
    if (l == r) {
      v[curr] = max(v[curr], val);
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
      update(2 * curr + 1, pos, val, l, mid);
    else
      update(2 * curr + 2, pos, val, mid + 1, r);
    v[curr] = max(v[2 * curr + 1], v[2 * curr + 2]);
  }
  void update(int pos, int val) { update(0, pos, val, 0, n - 1); }
  int ans() {
    int a = 0;
    for (auto val : v) a = max(a, val);
    return a;
  }
};
bool compare(pair<long long int, long long int>& a,
             pair<long long int, long long int>& b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
int find_set(vector<int>& parent, int x) {
  if (parent[x] == x) return x;
  return parent[x] = find_set(parent, parent[x]);
}
void union_set(vector<int>& parent, int x, int y) {
  x = find_set(parent, x);
  y = find_set(parent, y);
  if (x != y) {
    parent[x] = y;
  }
}
void pre() {}
void solve2() {
  long long int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<pair<long long int, long long int>, long long int> > > v(
      n, vector<pair<pair<long long int, long long int>, long long int> >(m));
  v[0][0] = {{0, 0}, 1};
  long long int ans = 1;
  for (int i = 1; i < m; i++) {
    v[0][i] = {{0, 1}, 1};
    ans += 2;
  }
  for (int i = 1; i < n; i++) {
    v[i][0] = {{1, 0}, 1};
    ans += 2;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      v[i][j] = {{v[i - 1][j].first.second + v[i - 1][j].second,
                  v[i][j - 1].first.first + v[i][j - 1].second},
                 1};
      ans += v[i][j].first.first;
      ans += v[i][j].first.second;
      ans += v[i][j].second;
    }
  }
  for (int i = 0; i < q; i++) {
    long long int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (v[x][y].second == 1) {
      ans -= v[x][y].second;
      ans -= v[x][y].first.second;
      ans -= v[x][y].first.first;
      v[x][y] = {{0, 0}, 0};
    } else {
      if (x == 0) {
        if (y == 0) {
          v[x][y] = {{0, 0}, 1};
        } else {
          v[x][y] = {{0, 1}, 1};
        }
      } else {
        if (y == 0) {
          v[x][y] = {{1, 0}, 1};
        } else {
          v[x][y] = {{v[x - 1][y].first.second + v[x - 1][y].second,
                      v[x][y - 1].first.first + v[x][y - 1].second},
                     1};
        }
      }
      ans += v[x][y].first.first;
      ans += v[x][y].first.second;
      ans += v[x][y].second;
    }
    while (x < n && y < m) {
      if (x < (n - 1)) {
        if (v[x + 1][y].second != 0) {
          ans -= v[x + 1][y].first.first;
          ans -= v[x + 1][y].first.second;
          ans -= v[x + 1][y].second;
          if (y == 0) {
            v[x + 1][y] = {{v[x][y].first.second + v[x][y].second, 0}, 1};
          } else {
            v[x + 1][y] = {
                {v[x][y].first.second + v[x][y].second,
                 v[x + 1][y - 1].first.first + v[x + 1][y - 1].second},
                1};
          }
          ans += v[x + 1][y].first.first;
          ans += v[x + 1][y].first.second;
          ans += v[x + 1][y].second;
        }
      }
      if (y < (m - 1) && v[x][y + 1].second != 0) {
        ans -= v[x][y + 1].first.first;
        ans -= v[x][y + 1].first.second;
        ans -= v[x][y + 1].second;
        if (x == 0) {
          v[x][y + 1] = {{0, v[x][y].first.first + v[x][y].second}, 1};
        } else {
          v[x][y + 1] = {{v[x - 1][y + 1].first.second + v[x - 1][y + 1].second,
                          v[x][y].first.first + v[x][y].second},
                         1};
        }
        ans += v[x][y + 1].first.first;
        ans += v[x][y + 1].first.second;
        ans += v[x][y + 1].second;
      }
      if (x < (n - 1) && y < (m - 1) && v[x + 1][y + 1].second != 0) {
        ans -= v[x + 1][y + 1].first.first;
        ans -= v[x + 1][y + 1].first.second;
        ans -= v[x + 1][y + 1].second;
        v[x + 1][y + 1] = {{v[x][y + 1].first.second + v[x][y + 1].second,
                            v[x + 1][y].first.first + v[x + 1][y].second},
                           1};
        ans += v[x + 1][y + 1].first.first;
        ans += v[x + 1][y + 1].first.second;
        ans += v[x + 1][y + 1].second;
      }
      x += 1;
      y += 1;
    }
    cout << ans << "\n";
  }
}
int main() {
  judge();
  fastio();
  pre();
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve2();
    cout << " \n";
  }
  cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
  return 0;
}
