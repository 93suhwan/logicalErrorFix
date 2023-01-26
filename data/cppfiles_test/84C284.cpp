#include <bits/stdc++.h>
using namespace std;
long long int mod1(long long int x) {
  return (((x % 1000000007) + 1000000007) % 1000000007);
}
long long int mul(long long int a, long long int b) {
  return mod1(mod1(a) * mod1(b));
}
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int h = (n / 2) + 1;
  long long int p = s / h;
  cout << p << "\n";
}
