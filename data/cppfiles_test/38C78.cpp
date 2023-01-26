#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n % 2) n++;
    cout << max(15ll, n / 2 * 5) << '\n';
  }
  return 0;
}
