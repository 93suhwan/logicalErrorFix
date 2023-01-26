#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1)
      cout << 1 << "\n";
    else {
      if (n == 2)
        cout << 2 << " " << 3 << "\n";
      else {
        long long int n1 = 11;
        for (long long int i = 1; i <= n; i++) {
          cout << n1 << " ";
          n1 = n1 * 10 + 1;
        }
        cout << "\n";
      }
    }
  }
}
