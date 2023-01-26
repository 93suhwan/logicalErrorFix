#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long int t;
  cin >> t;
  while (t--) {
    long long int n, k = 1;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        k++;
      }
    }
    if (k == n) {
      cout << "0" << endl;
    } else {
      for (long long int i = 0; i < n - 1; i++) {
        sort(a, a + n);
        a[n - 1] = a[n - 1] - 1;
        a[0] = a[0] + 1;
        if ((*max_element(a, a + n) - *min_element(a, a + n)) == 0) {
          cout << "0" << endl;
          break;
        } else if ((*max_element(a, a + n) - *min_element(a, a + n)) == 1) {
          cout << "1" << endl;
          break;
        }
      }
    }
  }
  return 0;
}
