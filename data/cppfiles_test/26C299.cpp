#include <bits/stdc++.h>
using namespace std;
vector<long long> v = {1, 1};
long long last = 1;
void factorial(long long n) {
  const unsigned int M = 1000000007;
  unsigned long long f = 1;
  for (int i = 3; i <= n; i++) {
    v.push_back((v[i - 2] * i) % M);
  }
}
void solve() {
  long long n;
  cin >> n;
  unsigned long long ans = ((v[2 * n - 1])) % 1000000007;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  factorial(2 * 10e5 + 1);
  while (t--) {
    solve();
    cout << "\n";
  }
}
