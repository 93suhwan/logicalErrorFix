#include <bits/stdc++.h>
using namespace std;
char orz[300001];
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", orz + 1);
    int rrr = 1;
    for (int i = 1; i <= n; i++) {
      if (orz[i] == '+')
        orz[i] = orz[i - 1] + 1 * rrr;
      else
        orz[i] = orz[i - 1] - 1 * rrr;
      rrr *= -1;
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      int eee = abs(orz[r] - orz[l - 1]);
      if (eee != 0) {
        if (eee % 2 == 1) eee = 1;
        if (eee % 2 == 0) eee = 2;
      }
      cout << eee << endl << endl;
    }
  }
}
