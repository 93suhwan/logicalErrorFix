#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main() {
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> n;
    k = 2;
    cout << k << " ";
    for (int i = 1; i < n; i++) {
      k = k * 2 + 1;
      cout << k << " ";
    }
    cout << endl;
  }
}
