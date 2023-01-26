#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
long long MOD = (1ll << 31) - 1;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  for (long long(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for (long long(bit) = (31); (bit) >= (0); (bit)--) {
      long long bt = 1ll << bit;
      long long lim = (ans ^ n) | bt;
      if (m >= lim - 1) {
        ans += bt;
      }
    }
    if ((n ^ ans) <= m) ans++;
    if (m < n) ans = 0;
    ;
    cout << ans << endl;
  }
  return 0;
}
