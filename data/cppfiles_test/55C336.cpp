#include <bits/stdc++.h>
using namespace std;
long long int f(int k) {
  if (k == 0) return 1;
  long long int res = f(k - 1);
  return 4 * res % 1000000007 * res % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  long long int res = f(k - 1);
  cout << 6 * res % 1000000007 * res % 1000000007 << '\n';
}
