#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = a + 2 * b + 3 * c;
    if (sum % 2 == 0)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
}
