#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int Q, A, B;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> Q;
  while (Q--) {
    cin >> A >> B;
    if (abs(A - B) == 1 || A % 2 != B % 2)
      cout << -1 << '\n';
    else if (A - B == 0 && A)
      cout << 1 << '\n';
    else if (A - B == 0 && !A)
      cout << 0 << '\n';
    else
      cout << 2 << '\n';
  }
  return 0;
}
