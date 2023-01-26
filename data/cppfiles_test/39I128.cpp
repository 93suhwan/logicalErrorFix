#include <bits/stdc++.h>
using namespace std;
const int E5 = 1e5;
const int E6 = 1e6;
const int E7 = 1e7;
const int E9 = 1e9;
const int N = 107;
const long long INF = 1e18;
const double PI = 3.14159265358979;
const long long mod = E9 + 7;
int a[N], ans[N];
vector<int> up[N], down[N];
bool us[N];
void dfs(int v, int dire, int w) {
  cout << v << ' ' << w << '\n';
  us[v] = 1;
  a[v] = w;
  if (dire == 2) {
    dfs(v, 1, w);
    dfs(v, 0, w);
  } else if (dire == 1) {
    for (auto to : up[v]) {
      if (!us[to]) dfs(to, 1, w + 1);
    }
  } else {
    for (auto to : down[v]) {
      dfs(to, 0, w - 1);
    }
  }
}
int main() {
  int n, pos = 0, mn = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << "? ";
    int pos = 0;
    for (int j = 1; j <= n; ++j) {
      if (j == i) {
        cout << 2 << ' ';
        continue;
      }
      cout << 1 << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    if (i != x) {
      up[i].push_back(x);
      down[x].push_back(i);
    }
    cout << "? ";
    for (int j = 1; j <= n; ++j) {
      if (j == i) {
        cout << 1 << ' ';
        continue;
      }
      cout << 2 << ' ';
    }
    cout << endl;
    cin >> x;
    if (!x) mn = x;
    if (i != x) {
      up[x].push_back(i);
      down[i].push_back(x);
    }
  }
  dfs(mn, 1, 0);
  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
