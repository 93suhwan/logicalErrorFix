#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << 1 << " " << 0 << "\n";
      continue;
    }
    int k = n / 3;
    int a = (n - k) / 2;
    while (true) {
      if (k + 2 * a == n) {
        cout << k << " " << a << "\n";
        break;
      }
      k++;
      a = (n - k) / 2;
    }
  }
  return 0;
}
