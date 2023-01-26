#include <bits/stdc++.h>
using namespace std;
int N, M;
const int MAXN = 4e6 + 10;
long long f[MAXN], s[MAXN];
int main() {
  scanf("%d%d", &N, &M);
  f[N] = 1;
  s[N] = 1;
  for (int i = N - 1; i >= 1; i--) {
    f[i] = s[i + 1];
    for (int j = 2; j * i <= N; j++)
      f[i] = (f[i] + (s[j * i] - s[min(N, (i + 1) * j - 1) + 1] + M)) % M;
    s[i] = (s[i + 1] + f[i]) % M;
  }
  printf("%lld", f[1]);
  return 0;
}
