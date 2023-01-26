#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 10;
const int inf = 2e9 + 10;
const long long INF = 2e18 + 10;
const int mod = 1e9 + 7;
const char nl = '\n';
void solve() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (auto& inp : A) cin >> inp;
  bool C[105];
  for (auto& item : A) {
    memset(C, false, sizeof C);
    for (int i = 0; i < (n); i++) {
      if (A[i] % item == 0) C[i] = true;
    }
    int k, cn1 = 0, cn2 = 0;
    if (C[0] == true)
      k = 1;
    else
      k = 0;
    for (int i = 0; i < (n); i++) {
      if (k & 1) {
        if (C[i] != true)
          break;
        else
          cn1++;
      } else {
        if (C[i] != false)
          break;
        else
          cn2++;
      }
      k++;
    }
    if (abs(cn1 - cn2) <= 1 && cn1 + cn2 == n) {
      cout << item << nl;
      return;
    } else
      continue;
  }
  cout << 0 << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
