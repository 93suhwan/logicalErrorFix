#include <bits/stdc++.h>
long long int fpow(long long int x, long long int y,
                   long long int p = 1000000007) {
  x = x % p;
  long long int sum = 1;
  while (y) {
    if (y & 1) sum = sum * x;
    sum %= p;
    y = y >> 1;
    x = x * x;
    x %= p;
  }
  return sum;
}
long long int fact[2000007] = {0};
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i < 2000007; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int res = 1;
  res = fact[n];
  res = (res * (fpow(fact[r], 1000000007 - 2))) % 1000000007;
  res = (res * (fpow(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
long long int npr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int res = 1;
  res = fact[n];
  res = (res * (fpow(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
long long int modmul(long long int x, long long int y) {
  return (x * y) % 1000000007;
}
long long int modadd(long long int x, long long int y) {
  return (x + y) % 1000000007;
}
long long int modsub(long long int x, long long int y) {
  return (x - y + 1000000007) % 1000000007;
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (max(a, max(b, c)) > 2 * abs(a - b)) {
    cout << "-1\n";
    return;
  }
  int diff = abs(a - b);
  if (c - diff > 0)
    cout << c - diff << endl;
  else
    cout << c + diff << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
