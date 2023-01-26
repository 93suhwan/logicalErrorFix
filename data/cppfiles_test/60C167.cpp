#include <bits/stdc++.h>
using int_t = long long int;
using std::cin;
using std::cout;
using std::endl;
const int_t LARGE = 3e5;
const int_t INF = 1e10;
using real_t = long double;
const int_t mod = 998244353;
int_t power(int_t base, int_t index) {
  if (index < 0) index = (index % (mod - 1) + mod - 1) % (mod - 1);
  int_t result = 1;
  while (index) {
    if (index & 1) result = result * base % mod;
    index >>= 1;
    base = base * base % mod;
  }
  return result;
}
const int_t BITS = 30;
int main() {
  std::ios::sync_with_stdio(false);
  int_t T;
  cin >> T;
  while (T--) {
    static int_t arr[101];
    int_t n;
    cin >> n;
    for (int_t i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    const auto& operate = [&](int_t l, int_t r) {
      for (int_t i = 0; i <= r - l; i++) {
        arr[l + i] = (arr[l + i] & arr[r - i]);
      }
    };
    for (int_t i = 1; i <= n; i++) {
      for (int_t j = BITS; j >= 0; j--) {
        int_t b = (1ll << j);
        if (arr[i] & b) {
          for (int_t j = 1; j <= n; j++) {
            if (!(arr[j] & b)) {
              operate(std::min(i, j), std::max(i, j));
            }
          }
        }
      }
    }
    int_t maxval = 0;
    for (int_t i = 1; i <= n; i++) maxval = std::max(maxval, arr[i]);
    cout << maxval << endl;
  }
  return 0;
}
