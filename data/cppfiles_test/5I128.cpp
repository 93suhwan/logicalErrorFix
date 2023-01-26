#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T) {
    int n;
    cin >> n;
    string epi;
    string gpi;
    cin >> epi;
    cin >> gpi;
    vector<int> ep(n, 0);
    vector<int> gp(n, 0);
    int eps = 0, gps = 0;
    for (int i = 0; i < (int)n; i++) {
      if (epi[i] == '1') {
        ep[i] = 1;
        eps += 1;
      }
    }
    for (int i = 0; i < (int)n; i++) {
      if (gpi[i] == '1') {
        gp[i] = 1;
        gps += 1;
      }
    }
    if (eps == 0) {
      cout << gps << endl;
    } else if (gps == 0) {
      cout << 0 << endl;
    } else if (eps == n && gps == n) {
      cout << n << endl;
    } else {
      int ans = 0;
      for (int i = 0; i < (int)n; i++) {
        if (ep[i] == 0 && gp[i] == 1) {
          gp[i] = 0;
          ans++;
        } else if (ep[i] == 1) {
          if (i >= 1 && gp[i - 1] == 1) {
            ans++;
            gp[i - 1] = 0;
          } else if (i < n - 1 && gp[i + 1] == 1) {
            ans++;
            gp[i + 1] = 0;
          }
        }
      }
      cout << ans << endl;
    }
    T--;
  }
}
