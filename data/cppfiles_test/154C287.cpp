#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a[3];
    long long int i;
    for (i = 0; i < 3; i++) {
      cin >> a[i];
    }
    sort(a, a + 3);
    if (a[2] == (a[0] + a[1])) {
      cout << "YES" << endl;
      continue;
    }
    if ((a[0] == a[1] && a[2] % 2 == 0) || (a[1] == a[2] && a[0] % 2 == 0)) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}
