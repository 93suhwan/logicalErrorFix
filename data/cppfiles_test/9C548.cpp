#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    map<char, int> m;
    int i;
    int count = 0;
    for (i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }
    for (auto it : m) {
      if (it.second > 1) {
        count += 2;
      } else if (it.second == 1) {
        count += 1;
      }
    }
    cout << count / 2 << endl;
  }
}
