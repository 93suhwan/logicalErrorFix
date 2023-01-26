#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += a[i];
    }
    sum = sum / (n - 1) + a[n - 1];
    cout << sum << endl;
    t--;
  }
  return 0;
}
