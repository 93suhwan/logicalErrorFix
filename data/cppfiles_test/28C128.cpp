#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = a + b * 2 + c * 3;
    long long int res = sum - sum / 2;
    sum /= 2;
    cout << res - sum << '\n';
  }
}
