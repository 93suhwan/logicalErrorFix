#include <bits/stdc++.h>
using namespace std;
vector<long long> fact(10000000);
void findFact() {
  fact[0] = 1;
  fact[1] = 1;
  fact[2] = 1;
  for (int i = 3; i < 10000000; i++) {
    fact[i] = i * fact[i - 1] % 1000000007;
  }
}
void solve() {
  long long n;
  cin >> n;
  cout << fact[2 * n] % 1000000007 << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  findFact();
  while (t--) {
    solve();
  }
  return 0;
}
