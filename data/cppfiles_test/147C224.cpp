#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++) {
      freq[s[i]]++;
    }
    if (freq['E'] == n - 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
