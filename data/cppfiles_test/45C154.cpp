#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
long long n;
long long arr[MX];
long long gogo(long long x) {
  long long ans = 0;
  long long delta = 0;
  for (int i = 0; i < (n); i++) {
    if (arr[i] != x) {
      delta += (x - arr[i]);
    }
    ans += abs(delta);
    x ^= 1;
  }
  return ans;
}
void solve() {
  cin >> n;
  long long tote = 0, toto = 0;
  for (int i = 0; i < (n); i++) {
    cin >> arr[i];
    arr[i] = arr[i] % 2;
    if (arr[i] == 1) {
      toto++;
    } else {
      tote++;
    }
  }
  if (toto == tote) {
    cout << min(gogo(1), gogo(0)) << nl;
  } else if (abs(toto - tote) == 1) {
    if (toto < tote) {
      cout << gogo(0) << nl;
    } else if (toto > tote) {
      cout << gogo(1) << nl;
    }
  } else {
    cout << -1 << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
