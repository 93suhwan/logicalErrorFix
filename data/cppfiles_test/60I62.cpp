#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max = 0, j, min, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    max = 0;
    cin >> a;
    long int m[a];
    for (j = 0; j < a; j++) {
      cin >> m[j];
      if (m[j] > max) max = m[j];
    }
    j--;
    min = m[j];
    for (int k = 0; k < a; k++) {
      if ((m[k] & m[j]) < min) {
        min = (m[k] & m[j]);
      }
    }
    cout << min << endl;
  }
  return 0;
}
