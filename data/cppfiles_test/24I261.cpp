#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = (int)2e5 + 3;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> digit;
    while (n > 0) {
      digit.push_back(n % 10);
      n /= 10;
    }
    reverse(digit.begin(), digit.end());
    if (digit.size() == 1) {
      cout << (digit[0] == 9 ? 1 : 0) << "\n";
    } else {
      for (int i = 0; i <= digit.size() - 2; i++) {
        cout << digit[i];
      }
      cout << "\n";
    }
  }
  return 0;
}
