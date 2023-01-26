#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int mn = 0;
    for (int i = 1; i <= n; i++) {
      long long int temp;
      cin >> temp;
      mn = max(mn, (temp - i));
    }
    cout << mn << endl;
  }
}
