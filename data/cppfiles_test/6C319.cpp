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
int main() {
  cin >> n >> m;
  ans = n;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    arr[min(u, v)]++;
    if (arr[min(u, v)] == 1) ans--;
  }
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x != 3) {
      cin >> u >> v;
      arr[min(u, v)] += x == 1 ? 1 : -1;
      if (x == 1 && arr[min(u, v)] == 1) ans--;
      if (x == 2 && arr[min(u, v)] == 0) ans++;
    } else
      cout << (ans) << endl;
  }
}
