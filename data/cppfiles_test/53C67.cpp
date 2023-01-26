#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else {
    long long result = power(x, y / 2) % 1000000007;
    if (y % 2 == 0)
      return (result % 1000000007 * result % 1000000007) % 1000000007;
    else
      return (result % 1000000007 * result % 1000000007 * x % 1000000007) %
             1000000007;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  vector<long long> vs(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    vs[i] = v[i];
  }
  if (n == k) {
    cout << "YES"
         << "\n";
    return;
  }
  sort(vs.begin(), vs.end());
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    m[vs[i]] = i;
  }
  long long c = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long ele = v[i];
    if (v[i + 1] != vs[m[ele] + 1]) c++;
  }
  if (c + 1 > k)
    cout << "NO"
         << "\n";
  else
    cout << "YES"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
