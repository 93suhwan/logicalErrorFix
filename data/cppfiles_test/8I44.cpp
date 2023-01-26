#include <bits/stdc++.h>
using namespace std;
const long long INF = 2000000000000000LL;
int n, q;
int u, v;
long long a[100005];
vector<int> ver[100005];
int check;
struct state {
  int ind;
  long long illusions;
};
struct cmp {
  bool operator()(state a, state b) { return a.illusions > b.illusions; }
};
long long dijkstra(int st, int en) {
  priority_queue<state, vector<state>, cmp> h;
  h.push({st, 0});
  vector<long long> D(100005, INF);
  D[st] = 0;
  while (!h.empty()) {
    int ind = h.top().ind;
    int ill = h.top().illusions;
    h.pop();
    if (ind == en) {
      break;
    }
    if (D[ind] != ill) {
      continue;
    }
    for (auto nex : ver[ind]) {
      int illusions = ill + max(abs(a[nex] + a[ind]), abs(a[nex] - a[ind]));
      if (D[nex] > illusions) {
        D[nex] = illusions;
        h.push({nex, illusions});
      }
    }
  }
  return D[en];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    ver[u].push_back(v);
    ver[v].push_back(u);
  }
  while (q--) {
    cin >> check >> u >> v;
    if (check == 1) {
      a[u] = v;
    } else {
      cout << dijkstra(u, v) << "\n";
    }
  }
  return 0;
}
