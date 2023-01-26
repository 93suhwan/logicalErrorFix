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
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0' && i < n - 1) {
        sum += (s[i] - '0');
        sum++;
      }
      if (i == n - 1) {
        sum += s[i] - '0';
      }
    }
    cout << sum << endl;
  }
}
