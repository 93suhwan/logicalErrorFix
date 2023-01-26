#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const int mxx = 2e5 + 5;
const long long int INF = 1e18 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "a";
    n--;
    int rem = n % 3;
    n /= 3;
    if (n % 2) {
      for (int i = 0; i < n; i++) {
        s += "baa";
      }
    } else {
      if (n != 0) s += "cde";
      for (int i = 0; i < n - 1; i++) {
        s += "baa";
      }
    }
    if (rem == 1) s += 'x';
    if (rem == 2) s += "xy";
    cout << s << "\n";
  }
}
