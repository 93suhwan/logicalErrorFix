#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long countSC(long long N) {
  long long res =
      (long long)sqrt(N) + (long long)cbrt(N) - (long long)(sqrt(cbrt(N)));
  return res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << countSC(n) << endl;
  }
}
