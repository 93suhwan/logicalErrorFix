#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int an[N];
int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    memset(an, 0, sizeof an);
    for (int i = 1; i <= m; i++) {
      cin >> an[i];
    }
    int ans = 0;
    int wanc = 0, feif = -1, ii = 1;
    for (int i = 1; i <= m; i++) {
      if (an[i] <= ii) {
        wanc = ii;
      } else {
        feif = an[i];
        ans += feif - wanc - 1;
        wanc = feif;
        ii = feif;
      }
      ii++;
    }
    cout << ans << endl;
  }
}
