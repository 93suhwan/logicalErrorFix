#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a >= b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a <= b) {
    return a;
  }
  return b;
}
long long modpower(long long a, long long n, long long d = 1000000007) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % d) * (a % d)) % d;
      n--;
    } else {
      a = ((a % d) * (a % d)) % d;
      n /= 2;
    }
  }
  return res;
}
long long modadd(long long a, long long b, long long d = 1000000007) {
  return ((a % d) + (b % d)) % d;
}
long long modsubtract(long long a, long long b, long long d = 1000000007) {
  return ((a % d) - (b % d)) % d;
}
long long modproduct(long long a, long long b, long long d = 1000000007) {
  return ((a % d) * (b % d)) % d;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> input(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> input[i];
  }
  for (long long i = 1; i <= n; i++) {
    long long j = i + 1;
    bool possible = false;
    for (long long k = 2; k <= j; k++) {
      if (input[i] % j != 0) {
        possible = true;
      }
    }
    if (possible == false) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
