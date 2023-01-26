#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const double esp = 1e-2;
long long qpow(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    string str(n / 2, 'a');
    str += 'b';
    if (n % 2) {
      str += 'c';
    }
    str += string((n / 2) - 1, 'a');
    cout << str << endl;
  }
  return 0;
}
