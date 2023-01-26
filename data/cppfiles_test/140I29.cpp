#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int r = pow(n, 0.5);
    long long int s = cbrt(n);
    long long int r1 = pow(n, 1.0 / 6);
    cout << (r + s - r1) << '\n';
  }
}
