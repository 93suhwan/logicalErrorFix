#include <bits/stdc++.h>
using namespace std;
long long t, n, s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << s / (n / 2 + 1) << endl;
  }
}
