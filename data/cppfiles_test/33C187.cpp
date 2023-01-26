#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    cin >> v[0];
    long long max = 0;
    for (int i = 1; i < n; i++) {
      cin >> v[i];
      if (v[i] * v[i - 1] > max) max = v[i] * v[i - 1];
    }
    cout << max << endl;
  }
  return 0;
}
