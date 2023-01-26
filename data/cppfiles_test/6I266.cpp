#include <bits/stdc++.h>
using namespace std;
int n, m;
int u, v;
int q;
int ans = 0;
int ans_cpy = 0;
int k = 0;
int arr[200005] = {};
int arr_c[200005] = {};
void solve() {
  set<int> change_list;
  int c;
  ans_cpy = ans;
  while (q--) {
    k++;
    cin >> c;
    if (c == 1) {
      cin >> u >> v;
      if (change_list.find(u) == change_list.end()) {
        arr_c[u] = arr[u];
      }
      if (change_list.find(v) == change_list.end()) arr_c[v] = arr[v];
      change_list.insert(u);
      change_list.insert(v);
      if (u < v) {
        if (arr[u] == 0) {
          ans_cpy--;
        }
        arr[u]++;
      } else if (v < u) {
        if (arr[v] == 0) {
          ans_cpy--;
        }
        arr[v]++;
      }
    } else if (c == 2) {
      cin >> u >> v;
      if (change_list.find(u) == change_list.end()) {
        arr_c[u] = arr[u];
      }
      if (change_list.find(v) == change_list.end()) arr_c[v] = arr[v];
      arr_c[v] = arr[v];
      change_list.insert(u);
      change_list.insert(v);
      if (arr[u] > 0 && u < v) {
        if (arr[u] == 1) ans_cpy++;
        arr[u]--;
      }
      if (arr[v] > 0 && u > v) {
        if (arr[v] == 1) ans_cpy++;
        arr[v]--;
      }
    } else if (c == 3) {
      cout << (ans_cpy) << endl;
      return;
    }
  }
}
int main() {
  cin >> n >> m;
  ans = n;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u < v) {
      if (!arr[u]) ans--;
      arr[u]++;
    } else if (u > v) {
      if (!arr[v]) ans--;
      arr[v]++;
    }
  }
  cin >> q;
  while (q) {
    if (k >= q) exit(0);
    solve();
  }
}
