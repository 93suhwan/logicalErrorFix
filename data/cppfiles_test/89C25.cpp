#include <bits/stdc++.h>
using namespace std;
const long long N = 200010, M = 310, Mod = 998244353;
int n, m, a[N];
vector<long long> Adj[N];
bool Leaf[N], Bud[N];
void Dfs(int x = 1, int p = -1) {
  Leaf[x] = (Adj[x].size() == 1 && x != 1);
  bool IsBud = false;
  for (auto to : Adj[x]) {
    if (to == p) continue;
    Dfs(to, x);
    IsBud |= (Leaf[to]);
  }
  Leaf[x] |= !IsBud;
  IsBud &= (x != 1);
  Bud[x] = IsBud;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int T = 1; T <= TT; T++) {
    cin >> n;
    for (int i = 1; i <= n; i++) Adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      Adj[a].push_back(b);
      Adj[b].push_back(a);
    }
    Dfs(1);
    long long Ans = 0, CntBud = 0;
    for (int i = 1; i <= n; i++) {
      CntBud += Bud[i];
    }
    Ans = 2 * CntBud;
    bool hasLeaf = false;
    for (auto to : Adj[1]) {
      hasLeaf |= Leaf[to];
    }
    Ans += hasLeaf;
    cout << n - Ans << endl;
  }
  return 0;
}
