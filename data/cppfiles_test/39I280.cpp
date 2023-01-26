#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000ll * 1000000000ll;
const long long MOD = 1000000007;
const int N = 1000000;
bool isprime(int k) {
  for (int i = 2; i * i <= k; i++)
    if (k % i == 0) return false;
  return true;
}
long long solve() {
  int n;
  cin >> n;
  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    cout << "?";
    for (int j = 1; j <= n; j++)
      if (j == i)
        cout << " 1";
      else
        cout << " 2";
    cout << endl;
    int k;
    cin >> k;
    if (k != i) ans[k] = i;
    cout << "?";
    for (int j = 1; j <= n; j++)
      if (j == i)
        cout << " 2";
      else
        cout << " 1";
    cout << endl;
    cin >> k;
    if (k != i) ans[i] = k;
  }
  cout << "!";
  int k = 0;
  for (int i = 1; i <= n; i++) {
    cout << " " << ans[k];
    k = ans[k];
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    long long ans = solve();
  }
}
