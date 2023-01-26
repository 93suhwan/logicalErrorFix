#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, k, n, i;
  cin >> t;
  while (t--) {
    cin >> k;
    n = 1;
    i = 1;
    while (i != k) {
      n++;
      if ((n % 3 != 0) && (n % 10 != 3)) {
        i++;
      }
    }
    cout << n << endl;
  }
}
