#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int f = 1;
    for (long long int i = 1; i <= 2 * n; i++) {
      if (i == 2) {
        continue;
      }
      f = (f % 1000000007 * i % 1000000007) % 1000000007;
    }
    cout << f << endl;
  }
  return 0;
}
