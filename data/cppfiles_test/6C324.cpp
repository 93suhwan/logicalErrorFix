#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 2e5;
int curans;
vector<set<int> > adj(MXN);
int g[MXN];
int main() {
  int n, m;
  cin >> n >> m;
  curans = n;
  for (int x = 0; x < m; x++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a].insert(b);
    adj[b].insert(a);
    ++g[min(a, b)];
    if (g[min(a, b)] == 1) --curans;
  }
  int q;
  cin >> q;
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      adj[a].insert(b);
      adj[b].insert(a);
      ++g[min(a, b)];
      if (g[min(a, b)] == 1) --curans;
    } else if (qt == 2) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      adj[a].erase(b);
      adj[b].erase(a);
      --g[min(a, b)];
      if (g[min(a, b)] == 0) ++curans;
    } else {
      cout << curans << endl;
    }
  }
}
