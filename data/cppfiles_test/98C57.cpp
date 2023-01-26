#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, t, m;
  cin >> t;
  while (t--) {
    string r, s;
    cin >> s >> r;
    k = r.length();
    j = 0;
    for (i = 1; i < k; i++) {
      m = s.find(r[i - 1]) - s.find(r[i]);
      if (m < 0) {
        j -= m;
      } else {
        j += m;
      }
    }
    cout << j << endl;
  }
}
