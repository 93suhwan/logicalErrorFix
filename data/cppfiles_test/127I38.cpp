#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    if (b == "abc") reverse(a.begin(), a.end());
    cout << a << endl;
  }
}
