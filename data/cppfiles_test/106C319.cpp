#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int x = 2;
    for (int i = 0; i < n; i++) {
      cout << x << " ";
      x++;
    }
    cout << "\n";
  }
  return 0;
}
