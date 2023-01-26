#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, arr[105], brr[105];
  cin >> t;
  while (t--) {
    cin >> n;
    int x = n / 3;
    int y = n % 3;
    if (y == 0) {
      cout << x << " " << x << '\n';
    } else if (y == 2) {
      cout << x << " " << x + 1 << '\n';
    } else {
      cout << x + 1 << " " << x << '\n';
    }
  }
  return 0;
}
