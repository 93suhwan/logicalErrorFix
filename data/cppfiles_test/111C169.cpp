#include <bits/stdc++.h>
using namespace std;
const long long inf = long long(1e9) + 7;
int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        cout << '(';
      }
      for (int j = 0; j < i; ++j) {
        cout << ')';
      }
      for (int j = 1; j <= n - i; ++j) {
        cout << "()";
      }
      cout << '\n';
    }
  }
  return 0;
}
