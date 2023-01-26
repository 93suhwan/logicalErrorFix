#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else {
      if (n % 3 == 2) {
        long long c1 = n / 3;
        long long c2 = (n - c1) / 2;
        cout << c1 << " " << c2 << endl;
      } else if (n % 3 == 1) {
        long long c1 = (n / 3) + 1;
        long long c2 = (n - c1) / 2;
        cout << c1 << " " << c2 << endl;
      }
    }
  }
}
