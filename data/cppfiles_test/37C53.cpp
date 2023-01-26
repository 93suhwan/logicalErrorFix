#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r;
};
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    map<int, int> has;
    int fir = 0;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      has[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (!has[i]) {
        fir = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != fir) cout << i << " " << fir << endl;
    }
  }
  return 0;
}
