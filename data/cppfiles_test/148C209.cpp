#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long cases;
  cin >> cases;
  while (cases--) {
    long long w, h;
    cin >> w >> h;
    long long l;
    cin >> l;
    long long a1, a2, a3, a4;
    long long temp;
    long long b;
    for (long long i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a1 = (temp - b) * h;
    cin >> l;
    for (long long i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a2 = (temp - b) * h;
    cin >> l;
    for (long long i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a3 = (temp - b) * w;
    cin >> l;
    for (long long i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a4 = (temp - b) * w;
    cout << max({a1, a2, a3, a4}) << '\n';
  }
  return 0;
}
