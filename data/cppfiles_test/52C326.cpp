#include <bits/stdc++.h>
using namespace std;
int main() {
  long long cases;
  cin >> cases;
  while (cases) {
    long long n;
    cin >> n;
    long long arr[n];
    long long m = INT_MIN;
    double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      m = max(arr[i], m);
      sum += arr[i];
    }
    sum = sum - m;
    double ans = m;
    sum = sum / (n - 1);
    ans = ans + sum;
    cout << std::setprecision(10) << ans << endl;
    cases--;
  }
  return 0;
}
