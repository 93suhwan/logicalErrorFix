#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
int t;
ll n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cout << -(n - 1) << " " << n << "\n";
  }
}
