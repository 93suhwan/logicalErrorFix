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
    sort(a, a + n);
    int num = n / 2;
    int min = a[0];
    int k = 1;
    while (num--) {
      cout << a[k] << " " << min << endl;
      k++;
    }
  }
}
