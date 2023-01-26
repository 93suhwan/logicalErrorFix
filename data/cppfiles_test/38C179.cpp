#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n <= 6)
      cout << 15 << endl;
    else {
      long long int r = n % 6;
      long long int y = ((n - r - 6) / 6) * 15;
      if (r != 0) long long int y = ((n - r - 6) / 6) * 15;
      if (r + 6 <= 6)
        y = y + 15;
      else if (r + 6 <= 8)
        y = y + 20;
      else if (r + 6 <= 10)
        y = y + 25;
      else
        y = y + 30;
      cout << y << endl;
    }
  }
}
