#include <bits/stdc++.h>
using namespace std;
const unsigned long long int INF = 1000000000000000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int tt = n;
    while (n > 0) {
      for (int i = 1; i <= n; i++) {
        cout << '(';
      }
      for (int i = 1; i <= n; i++) {
        cout << ')';
      }
      for (int i = 1; i <= tt - n; i++) {
        cout << "()";
      }
      n--;
      cout << "\n";
    }
  }
  return 0;
}
