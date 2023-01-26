#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vii;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m % 2) {
      swap(n, m);
      k = n * m / 2 - k;
    }
    if (k * 2 > m * n)
      cout << "No\n";
    else if (n % 2 == 0 && k % 2 == 0)
      cout << "YES\n";
    else {
      k -= m / 2;
      if (k >= 0 && k % 2 == 0)
        cout << "YES\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
