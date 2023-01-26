#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> A(n);
  for (long long i = 0; i < n; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  map<long long, long long> M;
  for (long long i = 0; i < 2 * m; ++i) {
    if (M.find(A[i]) != M.end())
      M[A[i]]++;
    else
      M[A[i]] = 1;
  }
  long long ans = 0;
  for (long long i = 2 * m; i < n; ++i) {
    ans += A[i];
  }
  for (long long i = 0; i < m; ++i) {
    if (M.size() != 1) {
      auto U1 = M.begin();
      auto U2 = M.begin();
      U2++;
      M[(*U2).first]--;
      if (M[(*U2).first] == 0) {
        auto U3 = M.begin();
        U3++;
        M.erase(U3);
      }
      M[(*U1).first]--;
      if (M[(*U1).first] == 0) M.erase(M.begin());
    } else {
      ans += 1;
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long X;
  cin >> X;
  while (X--) solve();
}
