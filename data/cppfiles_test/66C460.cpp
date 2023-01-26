#include <bits/stdc++.h>
using namespace std;
const int INF_INT = 2147483647;
const long long INF_LL = 9223372036854775807LL;
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
void solve() {
  int n;
  cin >> n;
  long long tmp = 1;
  while (n) {
    if (tmp % 3 == 0 || tmp % 10 == 3) {
      tmp++;
      continue;
    }
    tmp++;
    n--;
  }
  cout << tmp - 1 << endl;
}
int main() {
  ios::sync_with_stdio();
  cin.tie();
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
