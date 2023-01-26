#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1 || n == 2) {
      cout << s << endl;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (s[i] - '0');
      if (s[i] != '0' && i < n - 1) {
        sum++;
      }
    }
    cout << sum << endl;
  }
}
