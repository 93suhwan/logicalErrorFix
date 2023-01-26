#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string sp;
    cin >> sp;
    string wordi;
    cin >> wordi;
    int ans = 0;
    int prev = 0;
    cin >> wordi;
    for (int i = 0; i < wordi.size(); i++) {
      for (int j = 0; j < sp.size(); j++) {
        if (wordi[i] == sp[j]) {
          int u = abs(j + 1 - prev);
          ans = ans + u;
          prev = j + 1;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
