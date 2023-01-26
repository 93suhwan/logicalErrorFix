#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, prei, prej, n, m, k, a, b, count, max;
  cin >> t;
  while (t--) {
    cin >> n;
    count = 0;
    count = n / 10;
    if (n % 10 == 9) count++;
    cout << count << "\n";
  }
}
