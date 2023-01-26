#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n / 2; i++) {
    cout << "a";
  }
  if (n % 2 == 0) {
    cout << "b";
  } else {
    cout << "bc";
  }
  for (int i = 0; i < n / 2 - 1; i++) {
    cout << "a";
  }
  cout << endl;
}
int main() {
  long long int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
