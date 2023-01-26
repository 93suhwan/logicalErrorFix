#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a[3], m;
    for (int i = 0; i < 3; i++) cin >> a[i];
    cin >> m;
    sort(a, a + 3);
    if (a[0] + a[1] < a[2] - 1)
      cout << "NO";
    else if (m > (a[0] - 1 + a[1] - 1 + a[2] - 1))
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
    ;
  }
  return 0;
}
