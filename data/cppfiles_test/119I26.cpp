#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int dif1 = 0, dif2 = 0;
    sort(a, a + n);
    if (a[0] == a[n - 1]) {
      cout << "0" << endl;
    } else {
      for (long long int i = 0; i < n - 1; i++) {
        sort(a, a + n);
        a[n - 1] = a[n - 1] - 1;
        a[0] = a[0] + 1;
        if (a[0] == a[n - 1]) {
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
