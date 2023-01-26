#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
template <typename T>
void print(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
}
template <typename T>
void input(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cin >> a[i];
}
template <typename T>
void print(vector<vector<T>>& a) {
  for (auto to : a) {
    for (auto v : to) cout << v;
    cout << '\n';
  }
  cout << '\n';
}
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<int> kek;
int siz = 0;
vector<vector<bool>> used;
long long n, m;
bool norm(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}
void dfs(int xi, int yi, vector<vector<int>>& a) {
  siz++;
  used[xi][yi] = true;
  for (int i = 0; i < 4; i++) {
    if (a[xi][yi] & (1 << i)) continue;
    int x = xi + dx[3 - i];
    int y = yi + dy[3 - i];
    if (norm(x, y) && !used[x][y]) dfs(x, y, a);
  }
}
long long kekrand(long long n) { return ((rand() << 16) + rand()) % n; }
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].insert(--b);
    g[b].insert(a);
  }
  long long to = 1e5;
  for (int i = 0; i < to; i++) {
    set<int> v;
    while (v.size() != 5) {
      v.insert(kekrand(n));
    }
    vector<int> a;
    for (auto to : v) {
      a.push_back(to);
    }
    bool flag = g[a[0]].count(a[1]);
    bool can = true;
    for (int j = 0; j < 5; j++) {
      for (int c = j + 1; c < 5; c++) {
        if (g[a[j]].count(a[c]) != flag) {
          can = false;
          break;
        }
      }
      if (!can) break;
    }
    if (can) {
      cout << a[0] + 1 << ' ' << a[1] + 1 << ' ' << a[2] + 1 << ' ' << a[3] + 1
           << ' ' << a[4] + 1;
      return;
    }
  }
  cout << -1;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) solve();
}
