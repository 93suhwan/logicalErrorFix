#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
bool vis[maxn];
void init() {
  vis[0] = vis[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    if (!vis[i]) {
      for (int j = i + i; j < maxn; j += i) vis[j] = 1;
    }
  }
}
int a[205];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int su = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      su += a[i];
    }
    if (vis[su]) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << i;
      }
      cout << endl;
      continue;
    }
    int id;
    for (int i = 1; i <= n; i++) {
      if (vis[su - a[i]]) {
        id = i;
        break;
      }
    }
    cout << n - 1 << endl;
    int k = 0;
    for (int i = 1; i <= n; i++) {
      if (i == id) continue;
      if (k == 0)
        k = 1;
      else
        cout << " ";
      cout << i;
    }
    cout << endl;
  }
  return 0;
}
