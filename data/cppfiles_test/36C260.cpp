#include <bits/stdc++.h>
using namespace std;
void solve();
vector<bool> primes;
void sieve();
int main() {
  sieve();
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    solve();
    cout << "\n";
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  copy_n(istream_iterator<int>(cin), n, a.begin());
  int sum = accumulate(a.begin(), a.end(), 0);
  if (!primes[sum]) {
    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    return;
  }
  cout << (n - 1) << "\n";
  int x =
      find_if(a.begin(), a.end(), [](int i) { return i % 2 != 0; }) - a.begin();
  for (int i = 1; i <= n; ++i) {
    if (1 + x == i) continue;
    cout << i << " ";
  }
}
void sieve() {
  constexpr int n = 20001;
  primes = vector<bool>(n, true);
  for (int i = 2; i != n; ++i) {
    if (!primes[i]) {
      continue;
    }
    for (int j = i * i; j < n; j += i) {
      primes[j] = false;
    }
  }
}
