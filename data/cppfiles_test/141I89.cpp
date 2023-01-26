#include <bits/stdc++.h>
using namespace std;
long long int pow2(long long int i) {
  long long int res = 1;
  while (i > 0) {
    res *= 10;
    i--;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int a, s;
    cin >> a >> s;
    long long int b = 0;
    long long int atemp, stemp;
    atemp = a;
    stemp = s;
    long long int i = 0;
    bool flag = false;
    while (atemp > 0) {
      if (stemp == 0) {
        flag = true;
        break;
      }
      long long int ai = atemp % 10;
      long long int si = stemp % 10;
      if (ai > si) {
        si = stemp % 100;
        long long int bi = si - ai;
        if (bi > 9) {
          flag = true;
          break;
        }
        b += bi * pow2(i);
        stemp /= 100;
      } else {
        long long int bi = si - ai;
        if (bi > 9) {
          flag = true;
          break;
        }
        b += bi * pow2(i);
        stemp /= 10;
      }
      atemp /= 10;
      i++;
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    while (stemp > 0) {
      long long int si = stemp % 10;
      long long int bi = si;
      b += bi * pow2(i);
      i++;
      stemp /= 10;
    }
    cout << b << endl;
  }
}
