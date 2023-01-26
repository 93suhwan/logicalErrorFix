#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double coins = float(n) / 3;
    if (coins == int(coins))
      cout << int(coins) << " " << int(coins) << endl;
    else
      cout << int(coins) + 1 << " " << int(coins) << endl;
  }
  return 0;
}
