#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int prime[N], phi[N], a[N], n, cnt;
int sum[N], m;
bool st[N];
vector<int> fac[N];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x >= y ? x - y : x - y + mod; }
void init() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!st[i]) {
      prime[++cnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt && 1ll * i * prime[j] < N; j++) {
      st[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }
}
int f(int n, int T) {
  int ans = 0;
  for (int i = T; i <= n; i += T) {
    for (auto it : fac[a[i]]) {
      ans = sub(ans, 1ll * phi[it] * sum[it] % mod * sum[it] % mod);
      sum[it]++;
      ans = add(ans, 1ll * phi[it] * sum[it] % mod * sum[it] % mod);
    }
  }
  for (int i = T; i <= n; i += T) {
    for (auto it : fac[a[i]]) {
      sum[it]--;
    }
  }
  return ans;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int T = 1; T <= n; T++) {
    ans = add(ans, 1ll * phi[T] * f(n, T) % mod);
  }
  printf("%d\n", ans);
  return 0;
}
