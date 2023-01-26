#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else if (n % 3 == 1) {
      cout << (n / 3) + 1 << " " << n / 3 << endl;
    } else {
      cout << (n / 3) << " " << (n / 3) + 1 << endl;
    }
  }
}
