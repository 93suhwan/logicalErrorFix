#include <bits/stdc++.h>
using namespace std;
long long int power(long long int n, long long int k) {
  long long int j = 1;
  if (k == 0) return 1;
  while (k > 0) {
    j = (j * n) % 1000000007;
    k--;
  }
  return j;
}
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[1] = false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, i, j, l, n, k, p, p1;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n], s = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n)
      cout << 1;
    else
      cout << 0;
    cout << "\n";
  }
  return 0;
}
