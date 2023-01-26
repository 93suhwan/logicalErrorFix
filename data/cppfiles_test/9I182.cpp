#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int sum = 0;
    string s;
    cin >> s;
    if (s.size() <= 2)
      cout << "0\n";
    else {
      for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) sum++;
      }
      cout << (s.size() - sum) / 2 << "\n";
    }
  }
}
