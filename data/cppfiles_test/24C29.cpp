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
    if (n < 9) {
      cout << 0 << endl;
    } else {
      cout << 1 + (n - 9) / 10 << endl;
      ;
    }
  }
}
