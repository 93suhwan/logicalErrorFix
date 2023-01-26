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
    string t = s;
    sort(t.begin(), t.end());
    int c = 0;
    for (int i = 0; i < s.size(); i++) c += (s[i] != t[i]);
    cout << c << "\n";
  }
}
