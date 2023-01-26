#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int maxl = 0, minl = 999999999;
    long long int n, k = 1;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
      cin >> array[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (array[i] == array[i + 1]) {
        k++;
      }
    }
    if (k == n) {
      cout << "0" << endl;
    } else {
      for (int i = 0; i < n; i++) {
        sort(array, array + n);
        array[0] = array[0] + 1;
        array[n - 1] = array[n - 1] - 1;
        maxl = max(maxl, array[i]);
        minl = min(minl, array[i]);
        if (array[i] == array[i + 1]) {
          k++;
        }
        if (k == n) {
          cout << 0 << endl;
          break;
        }
      }
      if (k != n) cout << maxl - minl << endl;
    }
  }
  return 0;
}
