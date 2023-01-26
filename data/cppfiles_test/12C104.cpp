#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int minv = 0, minh = 0;
    if (n % 2) minh = m / 2;
    if (m % 2) minv = n / 2;
    if (k >= minh && k <= (n * m) / 2 - minv && (k - minh) % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
