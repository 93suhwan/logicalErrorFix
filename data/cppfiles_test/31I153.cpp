#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    if (n % 2 == 0) {
      int k = 0;
      while (k < n) {
        long long int temp = a[k] * a[k + 1];
        cout << -1 * (temp / a[k]) << " " << temp / a[k + 1] << " ";
        k += 2;
      }
      cout << endl;
    } else {
      long long int temp = a[0] * a[1] * a[2];
      cout << -1 * (temp / a[0]) << " " << temp / (a[0] * a[1] * a[2]) << " "
           << (temp / a[2]) << " ";
      int k = 3;
      while (k < n) {
        long long int temp = a[k] * a[k + 1];
        cout << -1 * (temp / a[k]) << " " << temp / a[k + 1] << " ";
        k += 2;
      }
      cout << endl;
    }
  }
}
