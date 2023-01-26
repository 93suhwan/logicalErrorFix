#include <bits/stdc++.h>
using namespace std;
long long x, n;
long long list[100005];
int main() {
  cin >> x;
  while (n--) {
    bool g = 0;
    list[0] = -999999999;
    cin >> n;
    for (int z = 1; n >= z; z++) {
      cin >> list[z];
      if (list[z] <= list[z - 1]) g = 1;
    }
    if (0 == n % 2) {
      cout << "YES" << endl;
    } else {
      if (g) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
