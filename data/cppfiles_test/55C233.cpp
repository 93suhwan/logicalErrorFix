#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
  if (s.empty()) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
long long pot(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans % 1000000007 * a % 1000000007) % 1000000007;
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long n;
  cin >> n;
  n = (1ll << n) - 1;
  long long res = pot(4, n - 1);
  cout << (res * 6) % 1000000007 << "\n";
}
