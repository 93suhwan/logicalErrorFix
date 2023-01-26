#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll N = 100000000;
bitset<N / 2> isNotPrime;
vector<ll> primes = {2};
bool isPrime(ll x) {
  if (x < 2 || x % 2 == 0)
    return x == 2;
  else
    return !isNotPrime[x / 2];
}
void primeSieve() {
  for (ll i = 3; i < N; i += 2) {
    if (!isNotPrime[i / 2]) {
      primes.push_back(i);
      for (ll j = i * i; j < N; j += 2 * i) {
        isNotPrime[j / 2] = 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  primeSieve();
  ll T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll n;
    cin >> n;
    vector<ll> li(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
      cin >> li[i];
      s += li[i];
    }
    if (!isPrime(s)) {
      cout << n << "\n";
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << "\n";
    } else {
      cout << n - 1 << "\n";
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (li[i] % 2 == 1 && !found) {
          found = true;
          continue;
        }
        cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
}
