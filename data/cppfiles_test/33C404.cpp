#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, n, in, max;
  vector<long long> vec;
  cin >> t;
  while (t--) {
    cin >> n;
    max = -9999;
    for (i = 0; i < n; i++) {
      cin >> in;
      vec.push_back(in);
    }
    for (i = 0; i < n - 1; i++) {
      if (vec[i] * vec[i + 1] > max) {
        max = vec[i] * vec[i + 1];
      }
    }
    cout << max << endl;
    vec.clear();
  }
  return 0;
}
