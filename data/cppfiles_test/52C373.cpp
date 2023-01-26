#include <bits/stdc++.h>
using namespace std;
void ans() {
  int n;
  cin >> n;
  int array[n];
  for (int j = 0; j < n; j++) {
    cin >> array[j];
  }
  sort(array, array + n);
  double ans = 0;
  double avg = (accumulate(array, array + n - 1, 0.0)) / ((n - 1) * 1.0);
  ans = (double)array[n - 1] + avg;
  cout << fixed << setprecision(9) << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    ans();
  }
  return 0;
}
