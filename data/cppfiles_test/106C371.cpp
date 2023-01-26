#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000001] = {};
  a[0] = 1;
  a[1] = 1;
  for (int i = 2; i * i <= 1000001; i++) {
    if (!a[i]) {
      for (int j = i * i; j <= 1000001; j += i) a[j] = 1;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 0, j = 0;
    while (i < n) {
      if (!a[j]) {
        cout << j << " ";
        i++;
      }
      j++;
    }
    cout << "\n";
  }
}
