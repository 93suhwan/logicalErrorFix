#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void test() {
  int a;
  cin >> a;
  int ans = 1;
  for (int i = 3; i <= 2 * a; i++) {
    ans = (ans * i) % mod;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    test();
  }
  return 0;
}
