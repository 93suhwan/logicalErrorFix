#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long arr[N];
const long long mod = 1e9 + 7;
long long addt(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mult(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long subt(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long expt(long long x, long long n, long long m) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans = (ans * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return ans;
}
void solution() {
  long long n, m, x, i, j;
  cin >> n;
  cout << -(n - 1) << " " << n << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc, cs;
  tc = 1;
  cin >> tc;
  for (cs = 1; cs <= tc; cs++) {
    solution();
  }
  return 0;
}
