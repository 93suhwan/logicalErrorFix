#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2)
      cout << "NO\n";
    else {
      string word1 = "", word2 = "";
      for (int i = 0; i < s.size() / 2; i++) word1 += s[i];
      for (int i = s.size() / 2; i < s.size(); i++) word2 += s[i];
      if (word1 == word2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
