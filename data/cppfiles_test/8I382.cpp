#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int oo = 2e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << n / 3 << " " << (n - n / 3) / 2 + (n - n / 3) % 2 << "\n";
  }
}
