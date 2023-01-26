#include <bits/stdc++.h>
using namespace std;
int main() {
  double t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    float summ = 0, sum, sum1, sum2;
    sum = accumulate(a, a + n, summ) - *max_element(a, a + n);
    sum1 = sum / (n - 1);
    sum2 = *max_element(a, a + n) + sum1;
    cout << sum2 << endl;
  }
}
