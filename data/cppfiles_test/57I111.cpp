#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1;
  cin >> n;
  while (n--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
      cout << "YES" << endl;
    } else if (s < (n / k) * k + n) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
