#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n << " " << 1 - n << endl;
    } else {
      cout << n / 2 << " " << (n / 2) + 1 << endl;
    }
  }
  return 0;
}
