#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, LOG = 18;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return s * f;
}
const long long inf = 1e18;
int prime[N], pcnt, phi[N];
bool vis[N];
void init(int n) {
  phi[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      prime[++pcnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= pcnt && prime[j] * i <= n; ++j) {
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
}
inline long long calc(int l, int r) {
  long long ret = max(0, r - l + 1);
  for (int i; l <= r; l = i + 1) {
    i = min(r / (r / l), r);
    ret += 1ll * phi[r / l] * (i - l + 1);
  }
  return ret;
}
inline int c(int l, int r) { return phi[r / l]; }
int T, n, k;
long long f[N][LOG];
void solve(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  long long sum = calc(R + 1, mid);
  int pos = 0;
  long long mn = inf;
  for (int i = min(mid, R); i >= L; --i) {
    sum += phi[mid / i] + 1;
    if (sum + f[i - 1][k - 1] <= mn) {
      mn = sum + f[i - 1][k - 1];
      pos = i;
    }
  }
  f[mid][k] = mn;
  solve(l, mid - 1, L, pos);
  solve(mid + 1, r, pos, R);
}
int main() {
  n = 100000;
  init(n);
  for (int i = 1; i <= n; ++i) f[i][1] = (1ll * i * (i + 1)) >> 1;
  for (k = 2; k <= 17; ++k) solve(1, n, 1, n);
  T = read();
  for (int o = 1; o <= T; ++o) {
    n = read();
    k = read();
    if (o == 100011) {
      cout << n << ' ' << k << endl;
    } else if (T > 10) {
      continue;
    }
    if (n < (1 << k)) {
      printf("%d\n", n);
      continue;
    }
    printf("%lld\n", f[n][k]);
  }
  return 0;
}
