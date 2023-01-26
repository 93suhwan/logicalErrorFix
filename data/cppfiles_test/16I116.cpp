#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, temp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long m;
    cin >> m;
    string x;
    cin >> x;
    for (int k = 0; k < m; k++) {
      for (int l = 0; l < m; l++) {
        if (x[l] > x[k]) {
          temp = x[k];
          x[k] = x[l];
          x[l] = temp;
        }
      }
    }
    cout << x << endl;
  }
  return 0;
}
