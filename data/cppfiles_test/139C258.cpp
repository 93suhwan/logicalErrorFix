#include <bits/stdc++.h>
const unsigned int M = 1e9;
using namespace std;
int solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length() / 2;
    vector<char> vc;
    string st;
    string st1;
    for (int i = 0; i < n; i++) {
      vc.push_back(s[i]);
      st.push_back(s[i]);
    }
    for (int i = n; i < s.length(); i++) {
      st1.push_back(s[i]);
    }
    bool ch = true;
    if (st1 == st) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  clock_t z = clock();
  solve();
  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << " ";
  return 0;
}
