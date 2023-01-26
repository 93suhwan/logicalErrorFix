#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC target( \
    "f16c,xop,fma,fma4,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
long long n, a[200010], lft = 0, rht = 0;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> s;
  for (i = 0; i < n; i = j) {
    for (j = i; j < n; j++) {
      if (s[j] != s[i]) {
        break;
      }
    }
    reverse(a + i, a + j);
    for (k = i; k < j; k++) {
      if (s[k] == 'L') {
        if (lft > rht + a[k]) {
          printf("%lld R\n", a[k]);
          rht += a[k];
        } else {
          printf("%lld L\n", a[k]);
          lft += a[k];
        }
      } else {
        if (rht > lft + a[k]) {
          printf("%lld L\n", a[k]);
          lft += a[k];
        } else {
          printf("%lld R\n", a[k]);
          rht += a[k];
        }
      }
    }
  }
  return 0;
}
