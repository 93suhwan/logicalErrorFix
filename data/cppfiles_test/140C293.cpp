#include <bits/stdc++.h>
using namespace std;
long long mx = 1e7;
vector<long long> primelist;
vector<bool> prime(mx + 5, true);
void sieve() {
  prime[0] = prime[1] = false;
  for (long long i = 2; i <= mx; i++) {
    if (prime[i] == true) {
      primelist.push_back(i);
      for (long long j = i * i; j <= mx; j += i) {
        prime[j] = false;
      }
    }
  }
}
void solve() {
  long long i, j, n, k, c = 0, cube = 0;
  cin >> n;
  c = (long long)sqrt(n);
  k = (long long)cbrt(n);
  cout << c + k - (long long)sqrt(k) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, i = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
