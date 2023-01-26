#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = 0, j = s.size() / 2; i < s.size() / 2 && j < s.size();
         i++, j++) {
      if (s[i] == s[j]) {
        cnt++;
      }
    }
    if (cnt * 2 == s.size()) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
