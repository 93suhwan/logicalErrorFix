#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
long long const N = 2e5 + 7;
long long const OO = 1e16 + 7;
double const PI = 3.14159265358979323846;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, l, r, t;
  cin >> t;
  while (t--) {
    cin >> n;
    l = -1 * (n - 1);
    r = n;
    cout << l << " " << r << endl;
  }
  return 0;
}
