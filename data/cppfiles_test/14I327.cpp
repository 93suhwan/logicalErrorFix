#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t, k, c, d;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a, b, ans;
    for (int i = 0; i < n; i++) {
      cin >> c;
      a.push_back(c);
      b.push_back(c);
    }
    sort(b.begin(), b.end());
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      for (int j = n - 1 - i; j > -1; j--) {
        if (a[j] == b[i]) {
          cout << j + 1 << " " << n << " " << 1 << endl;
          a.erase(a.begin() + j);
          break;
        }
      }
    }
  }
  return 0;
}
