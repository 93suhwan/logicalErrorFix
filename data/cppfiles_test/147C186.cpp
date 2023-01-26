#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count_n = 0;
    for (auto c : s)
      if (c == 'N') count_n++;
    if (count_n == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
