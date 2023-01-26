#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      int num;
      cin >> num;
      cout << num << "\n";
      continue;
    }
    string num;
    cin >> num;
    int ans = num[n - 1] - '0';
    for (int i = 0; i < n - 1; i++) {
      if (num[i] == '0') continue;
      ans += num[i] - '0' + 1;
    }
    cout << ans << "\n";
  }
}
