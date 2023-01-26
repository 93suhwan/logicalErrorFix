#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n & 1) {
      n++;
    }
    cout << max(n / 2 * 5, (long long)15) << endl;
  }
  return 0;
}
