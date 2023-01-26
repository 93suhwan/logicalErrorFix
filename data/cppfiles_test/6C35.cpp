#include <bits/stdc++.h>
template <class p, class q>
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using ll = long long;
using VI = std::vector<int>;
using VLL = std::vector<ll>;
using namespace std;
using namespace std::chrono;
int n;
int const N = 1e5 + 3;
ll const P = 1e9 + 7;
int a[N];
int l[N];
int prime[N];
int phi[N];
int mult[N];
int ppower[N];
ll ans;
void sieve() {
  int p = 2;
  prime[1] = 0;
  phi[1] = 1;
  while (p < N) {
    ppower[p] = 1;
    if (prime[p]) {
      int cp = p;
      while (cp % prime[p] == 0) {
        cp /= prime[p];
        mult[p]++;
        ppower[p] *= prime[p];
      }
      phi[p] = (mult[p] >= 2) ? prime[p] * phi[p / prime[p]]
                              : (prime[p] - 1) * phi[p / prime[p]];
      p++;
      continue;
    }
    prime[p] = p;
    ppower[p] = p;
    mult[p] = 1;
    phi[p] = p - 1;
    for (ll i = 1LL * p * p; i < N; i += p) {
      if (!prime[i]) prime[i] = p;
    }
    p++;
  }
}
void write_divisors(int r, VI& output) {
  if (r == 1)
    output = {1};
  else {
    VI partial;
    write_divisors(r / ppower[r], partial);
    int prw = 1;
    for (int i = (0); i <= (mult[r]); i++) {
      for (const auto& u : partial) {
        output.push_back(prw * u);
      }
      prw *= prime[r];
    }
  }
}
VI divisors[N];
void uzup() {
  for (int i = (1); i <= (N - 1); i++) write_divisors(i, divisors[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  sieve();
  uzup();
  for (int j = (1); j <= (n); j++) {
    VI monitor;
    for (int k = j; k <= n; k += j) {
      for (const auto& u : divisors[a[k]]) {
        monitor.push_back(u);
        ans = (ans + 1LL * phi[u] * phi[j] * (2 * l[u] + 1)) % P;
        l[u]++;
      }
    }
    for (int i = (((int)((monitor).size())) - 1); i >= (0); i--) {
      l[monitor[i]]--;
      monitor.pop_back();
    }
  }
  cout << ans << "\n";
  return 0;
}
