#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = (s[s.size() - 1] - '0');
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i] == '0') {
        continue;
      } else {
        total += (s[i] - '0') + 1;
      }
    }
    cout << total << '\n';
  }
}
