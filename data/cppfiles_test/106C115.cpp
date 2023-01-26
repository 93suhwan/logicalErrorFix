#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool isPrime(long long n) {
  if (n == 2) return true;
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long fast_power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return fast_power(a, b / 2) * fast_power(a, b / 2);
  }
  return fast_power(a, b - 1) * a;
}
void solution() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n + 1; i++) cout << i << " ";
}
int32_t main() {
  fast();
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solution();
    cout << "\n";
  }
}
