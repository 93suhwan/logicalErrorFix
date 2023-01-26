#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n & 1) swap(n, m), k = m * n / 2 - k;
    cout << (((k & 1) || ((m & 1) && k > n * (m - 1) / 2)) ? "NO" : "YES")
         << "\n";
  }
}
