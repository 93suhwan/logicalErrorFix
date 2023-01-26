#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    string str;
    cin >> n >> str;
    long long int ans = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] - '0' != 0) ans += str[i] - '0';
      if (i != str.size() - 1 && str[i] - '0' != 0) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
