#include <bits/stdc++.h>
using namespace std;
long long int fact(int n) {
  long long int a = 1;
  while (n > 2) {
    a = (a * n--) % (1000000000 + 7);
  }
  return a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int ans = fact(2 * n);
    cout << ans % (1000000000 + 7) << endl;
  }
}
