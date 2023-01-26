#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int LCM(long long int a, long long int b) {
  if (b >= INT32_MAX) return b;
  return b * (a / gcd(a, b));
}
long long int pre[100001];
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> A(n);
  for (long long int &x : A) cin >> x;
  bool ans = true;
  for (long long int i = 0; i < n; i++) {
    ans &= (A[i] % pre[i] != 0);
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  pre[0] = 2;
  for (long long int i = 1; i <= 100000; i++) {
    pre[i] = LCM(i + 2, pre[i - 1]);
  }
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
