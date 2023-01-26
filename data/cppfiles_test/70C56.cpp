#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, q, x, s[200004][3];
int c[200004][3];
int mypow(int x, int t) {
  int ans = 1;
  for (; t; t >>= 1, x = (long long)x * x % M)
    if (t & 1) ans = (long long)ans * x % M;
  return ans;
}
bool answer(int N, int D, int s0, int s1, int s2) {
  int s = (long long)(s0 - (long long)c[N - 1][0] * D % M + M) % M *
          mypow(N, M - 2) % M;
  int tmp = (((long long)s * s % M * N % M +
              (long long)s * c[N - 1][0] * 2 % M * D % M) %
                 M +
             (long long)c[N - 1][1] * D % M * D % M) %
            M;
  if (tmp != s1) return 0;
  tmp = ((((long long)s * s % M * s % M * N % M +
           (long long)s * s * 3 % M * c[N - 1][0] % M * D % M % M) %
              M +
          (long long)s * c[N - 1][1] * 3 % M * D % M * D % M) %
             M +
         (long long)c[N - 1][2] * D % M * D % M * D % M) %
        M;
  return tmp == s2;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    s[i][0] = (x + s[i - 1][0]) % M;
    s[i][1] = ((long long)x * x % M + s[i - 1][1]) % M;
    s[i][2] = ((long long)x * x % M * x % M + s[i - 1][2]) % M;
    c[i][0] = (i + c[i - 1][0]) % M;
    c[i][1] = ((long long)i * i % M + c[i - 1][1]) % M;
    c[i][2] = ((long long)i * i % M * i % M + c[i - 1][2]) % M;
  }
  while (q--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int N = r - l + 1;
    puts(answer(N, d, (s[r][0] - s[l - 1][0] + M) % M,
                (s[r][1] - s[l - 1][1] + M) % M,
                (s[r][2] - s[l - 1][2] + M) % M)
             ? "Yes"
             : "No");
  }
}
