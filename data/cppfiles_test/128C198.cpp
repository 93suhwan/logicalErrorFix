#include <bits/stdc++.h>
using namespace std;
bool prime[31700 + 5];
vector<int> primes;
void sieve() {
  for (int i = 0; i < 31700 + 5; i++) prime[i] = true;
  prime[0] = prime[1] = false;
  for (int i = 2; i < 31700 + 5; i++) {
    if (prime[i] == false) continue;
    for (int j = i * i; j < 31700 + 5; j = j + i) {
      prime[j] = false;
    }
  }
  for (int i = 2; i < 31700 + 5; i++) {
    if (prime[i] == true) primes.push_back(i);
  }
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 0; i < (31700); i++) {
    if ((n - primes[i] - 1) % primes[i] != 0) {
      cout << primes[i] << " " << n - primes[i] - 1 << " 1\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
