#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj_list(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (v > u)
      adj_list[u - 1]++;
    else
      adj_list[v - 1]++;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (adj_list[i] == 0) {
      res++;
    }
  }
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int ope;
    cin >> ope;
    if (ope == 3) {
      cout << res << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      if (ope == 1) {
        if (v > u) {
          adj_list[u - 1]++;
          if (adj_list[u - 1] == 1) res--;
        } else {
          adj_list[v - 1]++;
          if (adj_list[v - 1] == 1) res--;
        }
      } else if (ope == 2) {
        if (u < v) {
          adj_list[u - 1]--;
          if (adj_list[u - 1] == 0) res++;
        } else {
          adj_list[v - 1]--;
          if (adj_list[v - 1] == 0) res++;
        }
      }
    }
  }
}
