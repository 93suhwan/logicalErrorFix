#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    int maxi = x[0];
    for (int i = 1; i < n; i++) {
      if (x[i] - x[i - 1] > maxi) maxi = x[i] - x[i - 1];
    }
    cout << maxi;
    cout << '\n';
  }
  return 0;
}
