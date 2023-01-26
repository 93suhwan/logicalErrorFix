#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    int cunt = 0;
    for (int i = 0; i < n; i++) {
      sum += s[i] - '0';
      if (i != n - 1) {
        if (s[i] != '0') {
          cunt++;
        }
      }
    }
    cout << sum + cunt << "\n";
  }
  return 0;
}
