#include <bits/stdc++.h>
using namespace std;
void solve() {
  int A[3] = {0};
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A + 3);
  if (A[0] + A[1] == A[2] || (A[0] == A[1] && A[2] % 2 == 0) ||
      (A[1] == A[2] && A[0] % 2 == 0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
