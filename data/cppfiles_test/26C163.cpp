#include <bits/stdc++.h>
const int N = 1e5 + 5;
const long long w = 1e9 + 7;
long long unsigned ans = 0;
using namespace std;
int main(void) {
  int T, n;
  cin >> T;
  for (int i = 0; i < T; i++) {
    ans = 1;
    cin >> n;
    for (int j = 2 * n; j > 2; j--) {
      ans *= j;
      ans = ans % w;
    }
    cout << ans << endl;
  }
  return 0;
}
