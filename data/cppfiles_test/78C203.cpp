#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, A, B;
    cin >> a >> b;
    int maxi = 0;
    maxi = max(maxi, b % a);
    int mid = b / 2;
    if (mid >= a) {
      maxi = max(maxi, b % mid);
    }
    if (mid - 1 >= a) {
      maxi = max(maxi, b % (mid - 1));
    }
    if (mid + 1 >= a) {
      maxi = max(maxi, b % (mid + 1));
    }
    cout << maxi << "\n";
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
