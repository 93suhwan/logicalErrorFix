#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long n, m;
bool st[N];
long long b[N];
vector<int> a;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long s = 1, MOD = 1e9 + 7;
    for (long long i = 1; i <= 2 * n; i++) {
      if (i != 2) {
        s = s * i;
        s %= MOD;
      }
    }
    printf("%lld\n", s);
  }
  return 0;
}
