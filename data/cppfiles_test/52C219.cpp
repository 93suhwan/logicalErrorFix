#include <bits/stdc++.h>
using namespace std;
int main() {
  double test;
  cin >> test;
  while (test--) {
    double n;
    cin >> n;
    vector<double> arr;
    for (double i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    double sum = 0;
    for (double i = 0; i < n - 1; i++) {
      sum += arr[i];
    }
    sum = sum / (n - 1);
    cout << fixed << setprecision(9) << (sum + arr[n - 1]);
    cout << endl;
  }
}
