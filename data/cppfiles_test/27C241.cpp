#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  long long int arr[16] = {0};
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || k <= 1 || m > (n * (n - 1) / 2))
      cout << "NO" << endl;
    else if (k > 3 || (k == 2 && n == 1) || (k == 3 && m == (n * (n - 1) / 2)))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
