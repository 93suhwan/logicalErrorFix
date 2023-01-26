#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int mod = 1e9 + 7;
long long phi[N], vis[N], prime[N];
vector<int> vv[N];
int cnt;
void init() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      prime[++cnt] = i;
      vis[i] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt; j++) {
      if (prime[j] > vis[i] || prime[j] >= N / i) break;
      vis[i * prime[j]] = prime[j];
      phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
    }
  }
}
long long a[N];
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      vv[j].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long ans = 0;
  unordered_map<long long, long long> mp;
  for (int i = 1; i <= n; i++) {
    long long tot = 0;
    mp.clear();
    for (int j = 1; j <= n / i; j++) {
      for (auto it : vv[a[j * i]]) {
        mp[it]++;
      }
    }
    for (auto it : mp) {
      tot = (tot + phi[it.first] * it.second % mod * it.second % mod) % mod;
    }
    ans = (ans + tot * phi[i] % mod) % mod;
  }
  printf("%lld\n", ans);
}
int main() {
  cnt = 0;
  init();
  run();
  return 0;
}
