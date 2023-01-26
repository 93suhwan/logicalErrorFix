#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    int x = v.back();
    double sum = 0.0;
    for (int i = 0; i < n - 1; i++) {
      sum = sum + v[i];
    }
    sum = sum / (n - 1);
    double ans = sum + v.back();
    cout << ans << endl;
  }
  return 0;
}
