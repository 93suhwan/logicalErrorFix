#include <bits/stdc++.h>
using namespace std;
const long long K = 998244353, N = 6 * 1e5 + 1, INF = 2e17;
vector<long long> d;
vector<vector<long long>> g;
vector<long long> w;
bool ok = 1;
long long bp(long long n, long long p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    long long res = bp(n, p / 2) % K;
    return (res * res) % K;
  } else {
    return (n * (bp(n, p - 1)) % K) % K;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 - 1 << " " << n / 2 << " " << 1 << "\n";
      continue;
    }
    if (n % 3 == 2) {
      cout << (n - 2) / 3 << " " << (2 * (n - 2) / 3 + 1) << " 1\n";
      continue;
    }
    if (n % 3 == 0) {
      cout << (n - 3) / 3 << " " << 2 * (n - 3) / 3 + 2 << " 1\n";
      continue;
    }
    if (n % 3 == 1) {
      cout << (n + 1) / 2 - 2 << " " << (n + 1) / 2 << " 1\n";
      continue;
    }
  }
}
