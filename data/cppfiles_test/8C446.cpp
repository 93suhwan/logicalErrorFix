#include <bits/stdc++.h>
using namespace std;
void solve();
auto mod = [](long long int n, long long int k) {
  long long int ans = n % k;
  if (n < 0) ans += k;
  return ans;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  cin >> tt;
  for (int T = 1; T < tt + 1; T++) solve();
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  long long int twos = n / 3;
  int rem = n - 3 * twos;
  cout << twos + (rem == 1) << " " << twos + (rem == 2) << "\n";
}
