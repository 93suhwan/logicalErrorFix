#include <bits/stdc++.h>
using namespace std;
long long int INF = 1ll * 1e18;
bool isprime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int ceil(long long int a, long long int b) {
  if (a % b == 0) return (a / b);
  return (1 + (a / b));
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int inverse(long long int y) { return power(y, 1000000007 - 2); }
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long int n, i, j;
    cin >> n;
    vector<long long int> A(n);
    for (i = 0; i < n; i++) cin >> A[i];
    string s;
    cin >> s;
    set<pair<long long int, long long int> > good, bad;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        good.insert({A[i], i});
      } else {
        bad.insert({A[i], i});
      }
    }
    vector<long long int> ans(n);
    long long int id = n;
    while (!good.empty()) {
      auto it = good.end();
      it--;
      ans[it->second] = id;
      id--;
      good.erase(it);
    }
    while (!bad.empty()) {
      auto it = bad.end();
      it--;
      ans[it->second] = id;
      id--;
      bad.erase(it);
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
