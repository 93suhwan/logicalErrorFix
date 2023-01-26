#include <bits/stdc++.h>
using namespace std;
int br[8], a1, a2, a3, ar[8];
int check(int a, int b, int c) {
  ar[0] = a;
  ar[1] = b;
  ar[2] = c;
  ar[3] = a + b;
  ar[4] = a + c;
  ar[5] = b + c;
  ar[6] = a + b + c;
  sort(ar, ar + 7);
  for (int i = 0; i < 7; i++)
    if (br[i] != ar[i]) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    for (int i = 0; i < 7; i++) cin >> br[i];
    for (int i = 0; i < 7; i++)
      for (int j = 0; j < 7; j++)
        for (int k = 0; k < 7; k++) {
          a1 = br[i];
          a2 = br[j];
          a3 = br[k];
          if (a1 + a2 + a3 == br[6]) {
            if (check(a1, a2, a3)) {
              printf("%d %d %d\n", a1, a2, a3);
              i = 7;
              j = 7;
              k = 7;
            }
          }
        }
  }
}
