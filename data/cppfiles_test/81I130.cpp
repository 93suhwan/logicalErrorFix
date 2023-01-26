#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char orz[300001];
char orz2[300001];
int rr;
int main() {
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int ful = 0;
    scanf("%s", orz + 1);
    while (q--) {
      int l, r;
      cin >> l >> r;
      rr = 0;
      for (int i = l; i <= r; i++) {
        orz2[++rr] = orz[i];
        if (rr >= 2 && orz2[rr] == orz2[rr - 1]) rr -= 2;
      }
      if (rr % 2 == 1) rr = 1;
      if (rr % 2 == 0) rr = 2;
      cout << rr << endl << endl;
    }
  }
}
