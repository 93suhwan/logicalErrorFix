#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s, c;
  int k;
  int a[100];
  while (t--) {
    cin >> c;
    cin >> s;
    k = 0;
    for (int i = 1; i < s.size(); i++) {
      k += abs(int(c.find(s[i])) - int(c.find(s[i - 1])));
    }
    cout << k << "\n";
  }
}
