#include <bits/stdc++.h>
using namespace std;
long long psa[4000101];
long long ans[4000101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long m;
  cin >> m;
  ans[n] = 1;
  psa[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    ans[i] += (psa[i + 1] % m);
    for (int j = 2; j <= n; j++) {
      if (j * i > n) break;
      ans[i] += (psa[j * i] - psa[min(n + 1, j * i + j)]) % m;
    }
    psa[i] = (psa[i + 1] + ans[i]) % m;
  }
  cout << ans[1] % m << "\n";
}
