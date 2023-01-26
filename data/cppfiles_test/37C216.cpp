#include <bits/stdc++.h>
using namespace std;
int mark[110000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int root;
    for (int i = 1; i <= n; i++) mark[i] = 0;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      mark[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (mark[i] == 0) {
        root = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i < root)
        cout << i << " " << root << "\n";
      else if (i > root)
        cout << root << " " << i << "\n";
    }
  }
}
