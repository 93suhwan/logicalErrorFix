#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, a, ma = 0, temp = 0;
    cin >> n;
    while (n--) {
      cin >> a;
      ma = max(ma, temp * a);
      temp = a;
    }
    cout << ma << endl;
  }
  return 0;
}
