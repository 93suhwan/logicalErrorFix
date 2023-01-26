#include <bits/stdc++.h>
using namespace std;
int pmod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    for (long long i = 1; i <= n / 2; i++) cout << 'a';
    cout << 'b';
    for (long long i = 1; i <= n / 2 - 1; i++) cout << 'a';
  } else {
    for (long long i = 1; i <= (n - 2) / 2; i++) cout << 'a';
    cout << "bc";
    for (long long i = 1; i <= (n - 2) / 2 + 1; i++) cout << 'a';
  }
  cout << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
}
