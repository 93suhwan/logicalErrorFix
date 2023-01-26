#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int N = 100007;
vector<int> prs;
int mu[N];
void sieve(int n) {
  vector<bool> isnt(n + 5);
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!isnt[i]) {
      prs.push_back(i);
      mu[i] = -1;
    }
    for (int p : prs) {
      ll x = p * i;
      if (x > n) break;
      isnt[x] = 1;
      if (i % p == 0) {
        mu[x] = 0;
        break;
      } else {
        mu[x] = -mu[i];
      }
    }
  }
}
int a[N];
ll sum[N], f[N], sig[N];
bool vis[N];
vector<int> vec[N];
int cnt[N];
void test() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      vec[j].push_back(i);
    }
  }
}
ll baoli(int n) {
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 7; j++) {
      int cur = 0;
      for (int k = i; k <= n; k += i) {
        if (a[k] % j == 0) ++cur;
      }
      printf("%d\n", cur);
      ans += sig[i] * sig[j] * cur * cur;
    }
  return ans;
}
int main() {
  sieve(N - 1);
  test();
  for (int i = 1; i < N; i++) {
    for (int j = i, t = 1; j < N; j += i, t++) {
      sig[j] += i * mu[t];
    }
  }
  for (int i = 1; i < N; i++) {
    sig[i] %= mod;
    sig[i] = (sig[i] + mod) % mod;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll res = 0;
    for (int j = i; j <= n; j += i) {
      for (int x : vec[a[j]]) {
        res = (res + (2 * sum[x] + 1) * sig[x]) % mod;
        sum[x]++;
      }
    }
    for (int j = i; j <= n; j += i) {
      for (int x : vec[a[j]]) {
        sum[x] = 0;
      }
    }
    ans = (ans + res * sig[i]) % mod;
  }
  printf("%lld\n", ans);
}
