#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int count = 0;
    while (!is_sorted(v.begin(), v.end())) {
      for (int i = count % 2; i < n - 1; i += 2) {
        if (v[i] > v[i + 1]) {
          swap(v[i], v[i + 1]);
        }
      }
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
