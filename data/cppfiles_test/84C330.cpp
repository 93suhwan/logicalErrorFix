#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    if (n <= 2)
      cout << (s / n);
    else {
      n = n - ((n + 1) / 2) + 1;
      cout << (s / n);
    }
    cout << endl;
  }
}
