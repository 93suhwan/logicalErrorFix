#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  long long mod = 1000000007;
  long long f = 6;
  int t = 1;
  long long p = 16;
  while (t < k) {
    f = (f * p) % mod;
    p = p * p % mod;
    t++;
  }
  cout << f << "\n";
}
