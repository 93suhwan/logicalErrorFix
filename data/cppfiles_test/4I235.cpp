#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    long long int n;
    cin >> n;
    string v, b;
    int r = 0;
    cin >> v >> b;
    for (int i = 0; i < n; i++) {
      if (b[i] == '1') {
        if (v[i] == '0') {
          r++;
        } else if (i - 1 >= 0 and v[i - 1] == '1') {
          r++;
        } else if (i + 1 < n and v[i + 1] == '1') {
          r++;
        }
      }
    }
    cout << r << endl;
    t--;
  }
}
