#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int T;
  cin >> T;
  while (T) {
    long long int n, m = 0;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0) {
        if (m < a[i] * a[i - 1]) m = a[i] * a[i - 1];
      }
    }
    cout << m << endl;
    T--;
  }
}
