#include <bits/stdc++.h>
using namespace std;
inline long long int sbt(long long int x) { return __builtin_popcount(x); }
inline long long int mul(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a * b) % m;
}
inline long long int add(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a + b) % m;
}
inline long long int sub(long long int a, long long int b,
                         long long int m = 1000000007) {
  return (a - b + m) % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if ((r + 1) / 2 >= l)
      cout << (r + 1) / 2 - 1 << "\n";
    else
      cout << r % l << "\n";
  }
}
