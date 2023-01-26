#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c = 2;
    for (int i = 0; i < n; i++) {
      cout << c << ' ';
      ++c;
    }
    cout << endl;
  }
}
