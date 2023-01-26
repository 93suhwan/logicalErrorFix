#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void ckadd(T& a, const T& b) {
  a = (a + b) % mod;
}
template <class T>
void cksub(T& a, const T& b) {
  a = (a - b + mod) % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int b[7];
    for (long long i = 0; i < int(7); ++i) {
      cin >> b[i];
    }
    int a[3];
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[6] - a[1] - a[0];
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
  }
  return 0;
}
