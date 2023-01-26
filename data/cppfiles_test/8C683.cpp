#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, sum = 0, i, j;
    cin >> n;
    int c1 = n / 3, c2 = n / 3;
    int rem = n % 3;
    c1 += rem % 2;
    c2 += (rem) / 2;
    cout << c1 << " " << c2;
    cout << "\n";
    cout.flush();
  }
  return 0;
}
