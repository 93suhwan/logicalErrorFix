#include <bits/stdc++.h>
using namespace std;
void solve(void);
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
  }
  return 0;
}
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int e = a + 2 * b + 3 * c;
  if (e % 2 == 0) {
    cout << "0" << endl;
  } else
    cout << "1" << endl;
}
