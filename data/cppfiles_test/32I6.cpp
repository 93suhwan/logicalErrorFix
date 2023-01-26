#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  fast();
  long long t, z;
  cin >> t;
  for (long long z = 1; z < t + 1; z++) {
    long long n;
    cin >> n;
    for (long long i = 1; i < 100; i++) {
      if (abs(n) % 2)
        n += i;
      else
        n -= i;
      cout << n << "\n";
    }
  }
}
