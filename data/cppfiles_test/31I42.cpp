#include <bits/stdc++.h>
using namespace std;
const int kmax = 19;
int seen[kmax][1 << kmax];
int n, k;
int main() {
  scanf("%i%i", &n, &k);
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%i", &val);
    for (int j = 0; j < k; j++) {
      seen[j][val]++;
      val = val / 2;
    }
  }
  for (int x = 0; x < (1 << k); x++) {
    int outp = 1 << k;
    for (int diff = 0; diff < k; diff++) {
      for (int a_high = 0; a_high < (1 << (k - 1 - diff)) && outp > 1;
           a_high++) {
        int low = a_high << (k - 1 - diff);
        int high = a_high << (k - 1 - diff);
        if ((x & (1 << diff)))
          low = low * 2 + 1, high = high * 2;
        else
          low = low * 2, high = high * 2 + 1;
        if (seen[diff][low] == 0 || seen[diff][high] == 0) continue;
        for (int j = diff - 1; j >= 0; j--) {
          int has = 0;
          if ((x & (1 << j))) has = 1;
          if (seen[j][low * 2 + (!has)] && seen[j][high * 2 + has])
            low = low * 2 + (!has), high = high * 2 + has;
          else if (seen[j][low * 2 + has] && seen[j][high * 2 + has])
            low = low * 2 + has, high = high * 2 + has;
          else if (seen[j][low * 2 + (!has)] && seen[j][high * 2 + (!has)])
            low = low * 2 + (!has), high = high * 2 + (!has);
          else
            low = low * 2 + has, high = high * 2 + (!has);
        }
        outp = min(outp, (high ^ x) - (low ^ x));
      }
    }
    printf("%i ", outp);
  }
  printf("\n");
  return 0;
}
