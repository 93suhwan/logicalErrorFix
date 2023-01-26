#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  long long a[7];
  cin >> t;
  while (t--) {
    for (int i = 0; i < 7; i++) cin >> a[i];
    sort(a, a + 7);
    cout << a[0] << " " << a[1] << " " << a[6] - a[1] - a[0] << '\n';
  }
  return 0;
}
