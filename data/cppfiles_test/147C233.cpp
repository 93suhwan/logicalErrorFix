#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int CASES;
  cin >> CASES;
  while (CASES--) {
    string s;
    cin >> s;
    int count = 0;
    for (int i{0}; i < s.size(); ++i) {
      if (s[i] == 'N') count++;
    }
    if (count == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
