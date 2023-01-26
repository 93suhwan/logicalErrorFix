#include <bits/stdc++.h>
using namespace std;
int Maxi(vector<vector<int> >& grid) {}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 6 == 0)
      cout << (n / 6) * 15 << endl;
    else if (n % 8 == 0)
      cout << (n / 8) * 20 << endl;
    else if (n % 10 == 0)
      cout << (n / 10) * 25 << endl;
    else {
      long long int ans = 0;
      ans = ans + (n / 10) * 25 + ((n % 10) / 8) * 20 + ((n % 10 % 8) / 6) * 15;
      if (n % 10 % 8 % 6 != 0) ans = ans + 15;
      cout << ans << endl;
    }
  }
}
