#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i = i + 2) {
    if (n % i == 0) return false;
  }
  return true;
}
long long twomutiplierwithminimumdiffrence(long long n) {
  int x = sqrt(n);
  int y = x;
  if (isprime(n)) {
    cout << 1 << " " << n;
    return 0;
  }
  while (1) {
    if (x * y == n)
      break;
    else if (x * y > n)
      x--;
    else
      y++;
  }
  return x;
}
long long largest_power(long long N) {
  N = N | (N >> 1);
  N = N | (N >> 2);
  N = N | (N >> 4);
  N = N | (N >> 8);
  N = N | (N >> 16);
  return (N + 1) >> 1;
}
long long fact(long long n) {
  if (n == 0) return 1;
  return ((n % 998244353) * (fact(n - 1)) % 998244353) % 998244353;
}
long long calculate(long long p, long long q) {
  long long expo;
  expo = 998244353 - 2;
  while (expo) {
    if (expo & 1) {
      p = (p * q) % 998244353;
    }
    q = (q * q) % 998244353;
    expo >>= 1;
  }
  return p;
}
void solution() {
  int n;
  int k;
  cin >> n;
  cin >> k;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int res = 0;
  int i = n - 2 * k;
  int j = n - 1;
  int z = 0;
  map<int, int> mp;
  while (i < n) {
    mp[a[i]]++;
    z = max(z, mp[a[i]]);
    i++;
  }
  res = max(0, z - k);
  for (int i = 0; i < n - 2 * k; i++) {
    res += a[i];
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solution();
  }
  return 0;
}
