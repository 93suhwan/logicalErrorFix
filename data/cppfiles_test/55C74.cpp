#include <bits/stdc++.h>
using namespace std;
long long md = 1e9 + 7;
const long long inf = 1e17;
long long bexp(long long a, long long b, long long c) {
  if (b == 0) return 1;
  if (b == 1) return a % c;
  long long r = bexp(a, b / 2, c);
  r = (r % c * r % c) % c;
  if (b % 2 == 0)
    return r % c;
  else
    return (r % c * a % c) % c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case = 1;
  while (test_case--) {
    long long i, j, n, k = 0, m = 0;
    cin >> n;
    long long ans = 0;
    long long p = (bexp(4ll, (1LL << n) - 2, md));
    ans = (p % md * 6ll % md) % md;
    cout << ans << "\n";
  }
  return 0;
}
