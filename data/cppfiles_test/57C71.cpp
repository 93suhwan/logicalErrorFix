#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long s, n, k;
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s < k)
      cout << "NO" << endl;
    else if (s == k)
      cout << "YES" << endl;
    else {
      long long tmp1 = (s % k) + 1;
      long long tmp2 = k - tmp1;
      long long res = 0;
      if ((s / k) % 2 == 0) {
        res = s + k - tmp2;
      } else {
        res = s + k - tmp1;
      }
      if (res >= 2 * n + 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
