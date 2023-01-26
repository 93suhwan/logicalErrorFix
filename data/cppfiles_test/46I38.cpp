#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int count = 0, num = INT_MIN;
    int maxn = *max_element(a, a + n);
    if (a[n - 1] == maxn) {
      cout << "0";
    } else {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == maxn) {
          count++;
          break;
        } else if (a[i] > num) {
          count++;
          num = a[i];
        }
      }
      cout << count - 1 << endl;
    }
  }
}
