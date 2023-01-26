#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    int s = 0;
    int b = a[n - 1];
    for (int j = n - 2; j >= 0; j--) {
      if (a[j] > b) {
        s++;
        b = a[j];
      }
    }
    cout << s << endl;
  }
}
