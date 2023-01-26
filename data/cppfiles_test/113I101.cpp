#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long n, i, j, m, a, b, c, k, q;
long long ar[300005], br[300005];
vector<long long> v1[300005];
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long x1, p1, x2, p2;
    scanf("%lld %lld", &x1, &p1);
    scanf("%lld %lld", &x2, &p2);
    if (x1 == x2 && p1 == p2) {
      cout << "=";
    } else {
      string s1 = to_string(x1);
      string s2 = to_string(x2);
      if (s1.length() + p1 > s2.length() + p2)
        cout << ">";
      else if (s1.length() + p1 < s2.length() + p2)
        cout << "<";
      else {
        int f1 = 0;
        for (int i = 0; i < min(s1.length(), s2.length()); i++) {
          if ((s1[i] - '0') > (s2[i] - '0')) {
            f1 = 1;
            break;
          }
          if ((s1[i] - '0') < (s2[i] - '0')) {
            f1 = 2;
            break;
          }
        }
        if (f1 == 0) cout << "=";
        if (f1 == 1) cout << ">";
        if (f1 == 2) cout << "<";
      }
    }
    printf("\n");
  }
}
