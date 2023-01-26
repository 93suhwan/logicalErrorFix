#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int val = (n * (n - 1)) / 2;
    if (m < n - 1 || m > val)
      cout << "NO\n";
    else if (k <= 1 || (k == 2 && n != 1))
      cout << "NO\n";
    else if (n == 1 && k > 1)
      cout << "YES\n";
    else if (k == 3 && m == val)
      cout << "YES\n";
    else if (k > 3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
