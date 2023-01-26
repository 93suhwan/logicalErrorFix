#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
set<int> edge[200001];
set<int> answer;
void input_solve_print() {
  cin >> N >> M;
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    if (u < v) {
      edge[u].insert(v);
    } else {
      edge[v].insert(u);
    }
  }
  for (int n = 1; n < N + 1; n++) {
    if (edge[n].size() == 0) {
      answer.insert(n);
    }
  }
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int query;
    cin >> query;
    if (query == 3) {
      cout << answer.size() << '\n';
    } else {
      int u, v;
      cin >> u >> v;
      if (u > v) {
        swap(u, v);
      }
      if (query == 1) {
        edge[u].insert(v);
        if (answer.find(u) != answer.end()) {
          answer.erase(u);
        }
      } else if (query == 2) {
        edge[u].erase(v);
        if (edge[u].size() == 0 && answer.find(u) == answer.end()) {
          answer.insert(u);
        }
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}
