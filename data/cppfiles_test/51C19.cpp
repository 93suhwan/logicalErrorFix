#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 0)
      cout << "-1 1\n";
    else if (n > 0)
      cout << 1 - n << " " << n << "\n";
    else
      cout << n << " " << -1 - n << "\n";
  }
  return 0;
}
