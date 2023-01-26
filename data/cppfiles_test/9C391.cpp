#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<char> uniqueV;
    for (int i = 0; i < s.length(); ++i) {
      if (count(uniqueV.begin(), uniqueV.end(), s[i]) < 2) {
        uniqueV.push_back(s[i]);
      }
    }
    cout << (uniqueV.size()) / 2 << "\n";
  }
  return 0;
}
