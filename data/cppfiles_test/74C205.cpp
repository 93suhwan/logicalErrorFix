#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0) {
      int ab = abs(a - b);
      int start = ab / 2;
      int it = a + b - start;
      vector<int> v;
      while (start <= it) {
        v.push_back(start);
        start += 2;
      }
      cout << v.size() << "\n";
      (v1, a, b, increment) for (long long int v1 = a; v1 < b;
                                 v1 = v1 + increment)(i, 0, v.size(), 1) {
        cout << v[i] << " ";
      }
      cout << "\n";
    } else {
      int ab = abs(a - b);
      int start = ab / 2;
      int it = a + b - start;
      vector<int> v;
      while (start <= it) {
        v.push_back(start);
        start += 1;
      }
      cout << v.size() << "\n";
      (v1, a, b, increment) for (long long int v1 = a; v1 < b;
                                 v1 = v1 + increment)(i, 0, v.size(), 1) {
        cout << v[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
