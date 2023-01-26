#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, e, k;
    cin >> n >> e >> k;
    k = k - 1;
    long long int temp = (n * (n - 1)) / 2;
    if (n == 1 and e == 0 and k >= 1) {
      cout << "YES" << endl;
      continue;
    }
    if (e < n - 1) {
      cout << "NO" << endl;
      continue;
    }
    if (e > temp) {
      cout << "NO" << endl;
      continue;
    }
    if (e == temp and k >= 2) {
      cout << "YES" << endl;
      continue;
    }
    if (e >= n - 1 and e < temp and k >= 3) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}
