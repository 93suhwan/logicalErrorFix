#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int r = n % 3;
    if (r == 1)
      cout << n / 3 + 1 << " " << n / 3;
    else if (r == 2)
      cout << n / 3 << " " << n / 3 + 1;
    else
      cout << n / 3 << " " << n / 3;
    cout << endl;
  }
  return 0;
}
