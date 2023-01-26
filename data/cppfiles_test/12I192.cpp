#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int k;
  cin >> k;
  while (k--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (k % 2 != 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      if (k >= (m / 2)) {
        k = k - (m / 2);
        if (k % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
