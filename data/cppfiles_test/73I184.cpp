#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a;
    vector<int> b;
    int x, temp, count = 1;
    for (auto i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
      b.push_back(x);
    }
    sort(b.begin(), b.end());
    if (a == b) {
      count = 0;
      cout << count << "\n";
    } else {
      while (count) {
        for (int i = 0; i < n - 1; i++) {
          if (a[i + 1] < a[i]) {
            temp = a[i + 1];
            a[i + 1] = a[i];
            a[i] = temp;
            i++;
          }
        }
        if (a == b) {
          break;
        }
        count++;
      }
      cout << count << "\n";
    }
  }
  return 0;
}
