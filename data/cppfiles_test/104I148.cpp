#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
int a[N], b[N];
char s[N];
int main() {
  re(t);
  while (t--) {
    re(n);
    int now = 0;
    for (int i = 1; i <= n; i++) re(a[i]), now ^= a[i];
    if (now) {
      puts("NO");
      continue;
    }
    vector<int> ans;
    int ok = 1;
    for (int i = 1; i <= n; i++)
      if (a[i]) {
        int j = i;
        while (j <= n && a[j]) j++;
        int cnt = j - i;
        while (cnt & 1) {
          while (j <= n && !a[j]) {
            if (j == n) {
              ok = 0;
              break;
            }
            if (!a[j + 1])
              ans.push_back(j - 1), a[j] = a[j + 1] = 1, j += 2;
            else {
              ans.push_back(j - 1), a[j - 1] = a[j] = a[j + 1] = 0;
              break;
            }
          }
          if (!ok) break;
          if (a[j]) {
            while (j <= n && a[j]) j++;
            cnt = j - i;
          } else
            break;
        }
        if (i > 1 && !a[i - 1]) {
          for (int k = i; k < j; k += 2) {
            ans.push_back(k);
            a[k] = a[k + 1] = 0;
          }
        } else if (j <= n && !a[j]) {
          for (int k = j - 2; k >= i; k -= 2) {
            ans.push_back(k);
            a[k] = a[k + 1] = 0;
          }
        } else
          ok = 0;
        i = j - 1;
      }
    if (!ok)
      puts("NO");
    else {
      puts("YES");
      printf("%d\n", (int)ans.size());
      if (ans.size()) {
        for (int i : ans) printf("%d ", i);
        puts("");
      }
    }
  }
}
