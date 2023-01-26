#include <bits/stdc++.h>
using namespace std;
int t, n, s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    n /= 2;
    n++;
    cout << (s / n) << endl;
  }
  return 0;
}
