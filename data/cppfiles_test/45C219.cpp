#include <bits/stdc++.h>
using namespace std;
int A[100000];
void solve() {
  int n;
  cin >> n;
  int prv = -1;
  for (int i = 0; i < (n); i++) cin >> A[i];
  int res = 1;
  for (int i = 0; i < (n); i++) {
    int x = A[i];
    ;
    ;
    if (x == 0) {
      if (prv == 0) {
        cout << "-1\n";
        return;
      }
    } else {
      if (prv != 1) {
        res++;
      } else {
        res += 5;
      }
    }
    prv = x;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10),
      cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
