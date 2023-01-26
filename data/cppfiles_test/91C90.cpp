#include <bits/stdc++.h>
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MR = 1e5 + 10;
const int MOD = 998244353;
int a[MR], ile[MR], mn[MR];
int suf[MR];
int main() {
  fast_io();
  int T;
  scanf("%d", &T);
  for (int xxx = 0; xxx < (T); ++xxx) {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = (1); i <= (n); ++i) {
      scanf("%d", &a[i]);
      mn[i] = a[i];
      ile[i] = 1;
      int stp = 0;
      for (int j = (i)-1; j >= (1); --j) {
        int tmp = ceil(a[j] / (double)mn[j + 1]);
        if (tmp == ile[j]) {
          stp = j;
          break;
        }
        ile[j] = tmp;
        mn[j] = a[j] / ile[j];
      }
      for (int k = (stp + 1); k <= (i); ++k)
        suf[k] = ((ile[k] - 1) * (long long)k + suf[k - 1]) % MOD;
      res = (res + suf[i]) % MOD;
    }
    printf("%d\n", res);
  }
  return 0;
}
