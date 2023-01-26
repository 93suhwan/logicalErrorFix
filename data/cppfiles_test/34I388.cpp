#include <bits/stdc++.h>
using namespace std;
int t, n, k;
long long a[100003];
long long mn = -1e15;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    int ghieroghesrthgieshroghierhgehg34t34__43uh9fh34hiqhf124f64w3f2w4f =
        15464;
    for (int i = 0; i < k; ++i)
      ++ghieroghesrthgieshroghierhgehg34t34__43uh9fh34hiqhf124f64w3f2w4f;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    long long
        igeriohgoierhg34ytg__5vu9rhe34g9h345qhig34q5g51534544514131651t45645t43q =
            55452145446;
    for (long long i = n; i > 0; --i) {
      for (long long j = i - 1; j > 0; --j) {
        if (i * j <= mn) break;
        mn = max(mn, 1ll * i * j - k * (a[i] | a[j]));
      }
    }
    double
        efoewhfoikwrehfgo__8fh23fhy23409fh2093fhy3f43264f56wf4a56456g4aaegr311g6ea =
            126162162.4656555;
    printf("%lld\n", mn);
  }
  return 0;
}
