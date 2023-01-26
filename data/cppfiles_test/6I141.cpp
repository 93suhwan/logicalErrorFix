#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solve(int n, int m, vector<int>& adj_list, vector<int>& cp_adj_list,
          int result, int& result_cp) {
  int ope;
  cin >> ope;
  if (ope == 3) {
    cp_adj_list.clear();
    for (int i : adj_list) {
      cp_adj_list.push_back(i);
    }
    cout << result_cp << "\n";
    result_cp = result;
    cout << " LL : " << result_cp << "\n";
  }
  return 0;
}
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
  vector<int> cp_adj_list;
  for (int i : adj_list) {
    cp_adj_list.push_back(i);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (cp_adj_list[i] == 0) {
      res++;
    }
  }
  int res_cp = res;
  int T;
  vector<pair<int, int>> revertOp;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int ope;
    cin >> ope;
    if (ope == 3) {
      for (auto [idx, op] : revertOp) {
        cp_adj_list[idx] += op;
      }
      revertOp.clear();
      cout << res_cp << "\n";
      res_cp = res;
    } else {
      int u, v;
      cin >> u >> v;
      if (ope == 1) {
        if (v > u) {
          cp_adj_list[u - 1]++;
          revertOp.push_back(make_pair(u - 1, -1));
          if (cp_adj_list[u - 1] == 1) res_cp--;
        } else {
          cp_adj_list[v - 1]++;
          revertOp.push_back(make_pair(v - 1, -1));
          if (cp_adj_list[v - 1] == 1) res_cp--;
        }
      } else if (ope == 2) {
        if (u < v) {
          cp_adj_list[u - 1]--;
          revertOp.push_back(make_pair(u - 1, 1));
          if (cp_adj_list[u - 1] == 0) res_cp++;
        } else {
          cp_adj_list[v - 1]--;
          revertOp.push_back(make_pair(v - 1, 1));
          if (cp_adj_list[v - 1] == 0) res_cp++;
        }
      }
    }
  }
}
