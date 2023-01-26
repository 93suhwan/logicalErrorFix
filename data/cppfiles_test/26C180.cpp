#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2004;
long long n, m;
long long a[maxn];
string s;
long long kq;
void btr(long long x) {
  if (x == 11) {
    long long c[2];
    c[1] = 0;
    c[0] = 0;
    for (long long i = 1; i <= 10; i++) {
      c[i % 2] += a[i];
      long long m1 = (10 - i) / 2, m2 = (10 - i + 1) / 2;
      if (c[0] > c[1] + m1 || c[1] > c[0] + m2) {
        kq = min(kq, i);
        break;
      }
    }
    return;
  } else {
    if (s[x] != '?') {
      a[x] = s[x] - 48;
      btr(x + 1);
    } else {
      for (long long i = 0; i <= 1; i++) {
        a[x] = i;
        btr(x + 1);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> s;
    s = " " + s;
    kq = 10;
    btr(1);
    cout << kq << endl;
  }
  return 0;
}
