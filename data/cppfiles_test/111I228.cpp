#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string ans;
    char x1 = '(', x2 = ')';
    for (int i = 0; i < n; i++) {
      ans.push_back(x1);
    }
    for (int i = 0; i < n; i++) ans.push_back(x2);
    cout << ans << "\n";
  }
}
