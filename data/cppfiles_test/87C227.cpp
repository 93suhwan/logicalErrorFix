#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long fact(long long n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int xorcompute(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void solved() {
  long long n, ans = 0, j = 1;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > j) {
      long long diff = v[i] - j;
      ans += diff;
      j += diff + 1;
    } else
      j++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solved();
  }
  return 0;
}
