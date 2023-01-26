#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1 << 30;
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    string x;
    cin >> x;
    int len = x.length();
    int ans1 = 0, ans2 = 0;
    int L = 0, R = len - 1;
    while (L <= R && x[L] == x[R]) {
      L++, R--;
    }
    if (L > R)
      printf("0\n");
    else {
      char a = x[L];
      int l = L, r = R;
      while (l <= r) {
        if (x[l] == x[r])
          l++, r--;
        else if (x[l] == a)
          ans1++, l++;
        else if (x[r] == a)
          ans1++, r--;
        else {
          ans1 = n + 1;
          break;
        }
      }
      char b = x[R];
      l = L, r = R;
      while (l <= r) {
        if (x[l] == x[r])
          l++, r--;
        else if (x[l] == b)
          ans2++, l++;
        else if (x[r] == b)
          ans2++, r--;
        else {
          ans2 = n + 1;
          break;
        }
      }
      int ans = min(ans1, ans2);
      if (ans1 == n + 1 && ans2 == n + 1) ans = -1;
      printf("%d\n", ans);
    }
  }
  return 0;
}
