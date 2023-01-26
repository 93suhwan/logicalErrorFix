#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int mod = 1e9 + 7;
vector<int> vv[N];
long long phi[N + 10], prime[N + 10];
int cnt = 0;
bool mark[N + 10];
void init() {
  int i, j;
  phi[1] = 1;
  for (i = 2; i <= N; i++) {
    if (!mark[i]) {
      prime[++cnt] = i;
      phi[i] = i - 1;
    }
    for (j = 1; j <= cnt; j++) {
      if (i * prime[j] > N) break;
      mark[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
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
  init();
  run();
  return 0;
}
