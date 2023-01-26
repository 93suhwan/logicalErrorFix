#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
      cout << 0 << "\n";
    else if (n == k)
      cout << 1 << "\n";
    else {
      if (abs(n - k) % 2 == 0)
        cout << 2 << "\n";
      else
        cout << "-1"
             << "\n";
    }
  }
  return 0;
}
