#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int n, m;
vector<pair<pair<int, int>, int>> g;
vector<pair<int, int>> v[200009], u[200009];
bool ok;
int w[200009];
bool chk[200009];
vector<int> q;
void Dfs2(int u, int f) {
  chk[u] = 1;
  for (auto i : v[u])
    if (chk[i.first] == 0 && i.first != f && i.second != -1) {
      w[i.first] = (w[u] ^ (__builtin_popcount(i.second) % 2));
      q.push_back(i.first);
      Dfs2(i.first, u);
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> m;
    g.clear();
    ok = true;
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
      u[i].clear();
    }
    fill(chk, chk + n + 1, 0);
    for (int i = 1; i <= n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      v[a].push_back({b, c});
      v[b].push_back({a, c});
      g.push_back({{a, b}, c});
    }
    for (int i = 1; i <= m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      u[a].push_back({b, c});
      u[b].push_back({a, c});
    }
    for (int i = n; i >= 1; --i) q.push_back(i);
    while ((int)q.size()) {
      int r = q.back();
      q.pop_back();
      if (chk[r] == 0) {
        chk[r] = 1;
        w[r] = 0;
      }
      for (auto i : u[r])
        if (chk[i.first] == 0) {
          chk[i.first] = 1;
          w[i.first] = (w[r] ^ i.second);
          q.push_back(i.first);
        }
      Dfs2(r, r);
    }
    for (int i = 1; i <= n; ++i) {
      for (auto j : v[i]) {
        if (j.second != -1 &&
            (w[i] ^ w[j.first]) != (__builtin_popcount(j.second) % 2))
          ok = false;
      }
      for (auto j : u[i]) {
        if ((w[i] ^ w[j.first]) != j.second) ok = false;
      }
    }
    if (ok == false)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto i : g) {
        cout << i.first.first << " " << i.first.second << " ";
        if (i.second == -1) {
          cout << (w[i.first.first] ^ w[i.first.second]) << "\n";
        } else
          cout << i.second << "\n";
      }
    }
  }
}
