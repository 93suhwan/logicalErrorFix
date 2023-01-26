#include <bits/stdc++.h>
using namespace std;
void debug_all() { cerr << "]\n"; }
template <typename T, typename... Types>
void debug_all(T var1, Types... var2) {
  cerr << ' ' << var1 << ' ';
  debug_all(var2...);
}
long long int binomialCoeff(int n, int k) {
  long long int C[n + 1][k + 1];
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc, n, z, o, ans;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<long long int> a(n);
    z = o = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        z++;
      } else if (a[i] == 1) {
        o++;
      }
    }
    ans = o;
    for (int i = 1; i <= z; i++) {
      ans += o * (binomialCoeff(z, i));
    }
    cout << ans << endl;
  }
  return 0;
}
