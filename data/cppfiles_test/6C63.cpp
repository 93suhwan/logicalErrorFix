#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100010;
int a[N];
int miu[N];
int dmiu[N];
int primes[N];
vector<int> fac[N];
bool vis[N];
int phi[N];
void init() {
  int tot = 0;
  miu[1] = phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      miu[i] = -1;
      primes[tot++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; i * primes[j] < N && j < tot; j++) {
      int x = i * primes[j];
      vis[x] = true;
      if (i % primes[j] == 0)
        miu[x] = 0, phi[x] = phi[i] * primes[j];
      else
        miu[x] = -miu[i], phi[x] = phi[i] * (primes[j] - 1);
      if (i % primes[j] == 0) break;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      dmiu[j] += miu[i] * (j / i);
      fac[j].push_back(i);
    }
  }
}
int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
long long sum[N];
int occ[N];
int times;
int solve(vector<int> &v) {
  long long ans = 0;
  ++times;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    for (int j = 0; j < fac[x].size(); j++) {
      int y = fac[x][j];
      if (occ[y] != times) {
        occ[y] = times;
        sum[y] = phi[y];
      } else {
        sum[y] += phi[y];
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    for (int j = 0; j < fac[x].size(); j++) {
      int y = fac[x][j];
      ans += sum[y];
    }
  }
  return ans % mod;
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> v;
    for (int j = i; j <= n; j += i) {
      v.push_back(a[j]);
    }
    ans = (ans + 1LL * dmiu[i] * solve(v)) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
