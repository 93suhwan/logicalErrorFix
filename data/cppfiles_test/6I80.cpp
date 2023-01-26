#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int phi[N];
int check[N];
int a[N];
vector<int> v[N];
int cnt[N], prime[N];
void init() {
  phi[1] = 1;
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i) {
      v[j].push_back(i);
    }
  for (int i = 2; i < N; i++) {
    if (!check[i]) {
      prime[++prime[0]] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= prime[0]; j++) {
      if ((long long)i * prime[j] >= N) break;
      check[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
      }
    }
  }
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> vv;
    for (int j = i; j <= n; j += i) {
      for (int d : v[a[j]]) {
        vv.push_back(d);
        cnt[d]++;
      }
    }
    long long tmp = 0;
    for (int d : vv) {
      tmp = (tmp + (((cnt[d] * cnt[d] % mod) * phi[d]) % mod)) % mod;
      cnt[d] = 0;
    }
    ans = (ans + tmp * phi[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
