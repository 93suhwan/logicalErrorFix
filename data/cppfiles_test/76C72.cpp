#include <bits/stdc++.h>
using namespace std;
void generate_subsets(vector<vector<int>> &sub_sets, vector<int> elements,
                      int missing_elem, int min_num, int max_num) {
  for (int el = min_num; el <= max_num - missing_elem + 1; el++) {
    elements[5 - missing_elem] = el;
    if (missing_elem == 1)
      sub_sets.push_back(elements);
    else {
      generate_subsets(sub_sets, elements, missing_elem - 1, el + 1, max_num);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  n = min(n, 48);
  vector<vector<bool>> adj_mat(n + 1, vector<bool>(n + 1));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (max(a, b) <= n) {
      adj_mat[a][b] = true;
      adj_mat[b][a] = true;
    }
  }
  vector<vector<int>> sub_sets;
  sub_sets.reserve(n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120);
  generate_subsets(sub_sets, vector<int>(5), 5, 1, n);
  bool party_exists = false;
  for (vector<int> sub_set : sub_sets) {
    bool all_connected = true, all_disconnected = true;
    for (int i = 0; i < 5; i++)
      for (int j = i + 1; j < 5; j++) {
        if (adj_mat[sub_set[i]][sub_set[j]])
          all_disconnected = false;
        else
          all_connected = false;
      }
    if (all_connected || all_disconnected) {
      for (int node : sub_set) cout << node << " ";
      cout << "\n";
      party_exists = true;
      break;
    }
  }
  if (!party_exists) cout << -1 << "\n";
  return 0;
}
