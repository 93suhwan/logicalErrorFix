#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> A(n);
  for (long long int &x : A) cin >> x;
  if (A[0] & 1)
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
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
