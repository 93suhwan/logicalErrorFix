#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long n, k, aa[10001], sum, cnt;
void solve() {
  cin >> n >> k;
  aa[0] = 1;
  for (int i = 1; i <= 32; i++) {
    aa[i] = ((aa[i - 1] % m) * (n % m)) % m;
  }
  while (k) {
    if (k % 2 != 0) {
      sum = (aa[cnt] + sum % m) % m;
    }
    k /= 2;
    cnt++;
  }
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
    sum = cnt = 0;
    for (int i = 0; i < 36; i++) {
      aa[i] = 0;
    }
  }
}
