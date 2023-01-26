#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
long long dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
long long dy[8] = {0, 1, -1, 0, -1, 1, -1, 1};
const int32_t mod = 1e9 + 7;
const long long inf = 1e18;
const long long N = 1e5 + 5;
long long add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (a + b) % mod;
}
long long sub(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (a - b + mod) % mod;
}
long long mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return ((a * b) % mod + mod) % mod;
}
long long bpow(long long n, long long x) {
  long long res = 1;
  while (x > 0) {
    if (x % 2 == 1) res = (res * n) % mod;
    n = (n * n) % mod;
    x /= 2;
  }
  return res;
}
void testCases() {
  long long n;
  cin >> n;
  vector<long long> V(n), ok(n);
  for (long long i = 0; i < n; i++) {
    cin >> V[i];
    ok[i] = V[i];
  }
  sort(V.begin(), V.end());
  vector<pair<long long, long long> > ans;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (V[i] == ok[j]) {
        ans.push_back({i, j});
        long long temp = ok[j];
        for (long long x = j; x > i; x--) {
          ok[x] = ok[x - 1];
        }
        ok[i] = temp;
        break;
      }
    }
  }
  cout << (long long)((ans).size()) << "\n";
  for (auto f : ans) {
    long long a = f.second - f.first;
    cout << f.first + 1 << " " << f.second + 1 << " " << a << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tcs = 1;
  cin >> tcs;
  while (tcs--) {
    testCases();
  }
}
