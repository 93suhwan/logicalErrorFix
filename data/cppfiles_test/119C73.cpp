#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10, MOD = 998244353, INF = 1e11;
void test(int tc);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, tc = 1;
  cin >> t;
  while (t--) test(tc++);
}
void test(int tc) {
  long long n;
  cin >> n;
  long long x, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
  }
  if (sum % n == 0)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";
}
