#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<vector<int>> alph(27);
    string key, s;
    cin >> key >> s;
    for (int i = 0; i < key.size(); ++i) {
      alph[key[i] - 'a'].push_back(i + 1);
    }
    int ans = 0;
    int index = alph[s[0] - 'a'][0];
    for (int i = 1; i < s.size(); ++i) {
      char target = s[i];
      ans +=
          (index == alph[target - 'a'][0] ? 0
                                          : abs(index - alph[target - 'a'][0]));
      index = alph[target - 'a'][0];
    }
    cout << ans << "\n";
  }
}
