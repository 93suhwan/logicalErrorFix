#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i, n, k;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 10 == 9)
      cout << 1 + n / 10 << "\n";
    else
      cout << n / 10 << "\n";
  }
  return 0;
}
