#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
void solution();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  ll t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
void solution() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << abs(abs(3 * c % 2 - 2 * b % 2) - a % 2) << endl;
}
