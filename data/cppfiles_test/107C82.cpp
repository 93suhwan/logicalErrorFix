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
    long long n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1) {
      cout << -1 << "\n";
      continue;
    }
    vector<long long> ans;
    if (b > a) ans.push_back(n);
    for (long long i = 0; i < int(n - 1); ++i) {
      ans.push_back(i + 1);
    }
    if (a >= b) ans.push_back(n);
    int i = 1;
    if (b > a) i++;
    if (b > a && i < n) b--;
    while (i < n - 1 && a) {
      swap(ans[i], ans[i + 1]);
      a--;
      i += 2;
      if (i < n) b--;
      if (b == -1) {
        i -= 2;
        swap(ans[i], ans[i + 1]);
        for (int k = 0; i + k < n - 1 - k; k++) {
          swap(ans[i + k], ans[n - 1 - k]);
        }
        b++;
        break;
      }
    }
    if (a == 0 && b == 0) {
      for (auto e : ans) {
        cout << e << " ";
      }
      cout << "\n";
    } else
      cout << -1 << "\n";
  }
}
