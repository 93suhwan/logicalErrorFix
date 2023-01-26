#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long M = 1000000007;
const long long INF = 1e18;
const long long N = 100005;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 and m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  } else if (n % 2 != 0) {
    if ((k - m / 2) % 2 == 0 and k >= m / 2) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  } else {
    long long p = n * m / 2 - n / 2;
    if (k % 2 == 0 and k <= p) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long no;
  cin >> no;
  while (no--) {
    solve();
  }
  return 0;
}
