#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  unordered_map<char, int> m;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    int count = 0;
    string s;
    cin >> s;
    int n = s.length();
    m.clear();
    for (int i = 0; i < n; i++) {
      m[s[i]]++;
    }
    for (auto temp : m) {
      if (temp.second > 1) count++;
    }
    count += (m.size() - count) / 2;
    cout << count << endl;
  }
}
