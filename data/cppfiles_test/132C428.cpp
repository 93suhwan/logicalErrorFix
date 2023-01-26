#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a[7];
    for (auto &it : a) {
      cin >> it;
    }
    cout << a[0] << " " << a[1] << " ";
    if (a[2] == a[1] + a[0]) {
      cout << a[3] << endl;
    } else {
      cout << a[2] << endl;
    }
  }
  return 0;
}
