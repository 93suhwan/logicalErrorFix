#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), countA = 0, countB = 0, countC = 0;
    for (int i = 0; i < n; i++) {
      countA += (s[i] == 'A');
      countB += (s[i] == 'B');
      countC += (s[i] == 'C');
    }
    if (countB == countA + countC) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
