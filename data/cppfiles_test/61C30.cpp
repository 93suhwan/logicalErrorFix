#include <bits/stdc++.h>
using namespace std;
vector<int> findPrimes(int n) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<int> pr;
  for (int p = 2; p <= n; p++)
    if (prime[p]) pr.push_back(p);
  return pr;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ca(n + 1), cb(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      ca[a[i]]++;
      cb[b[i]]++;
    }
    long long res = 0;
    res = (n) * (n - 1LL) * (n - 2LL);
    res /= 6LL;
    for (int i = 0; i < n; i++) {
      res -= ((ca[a[i]] - 1LL) * (cb[b[i]] - 1LL));
    }
    cout << res << endl;
  }
}
