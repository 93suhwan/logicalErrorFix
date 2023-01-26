#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, n_2 = 0, n_1 = 0;
    cin >> n;
    n_2 = n_1 = n / 3;
    if (n % 3 == 1)
      n_1++;
    else if (n % 3 == 2)
      n_2++;
    cout << n_1 << " " << n_2 << endl;
  }
  return 0;
}
