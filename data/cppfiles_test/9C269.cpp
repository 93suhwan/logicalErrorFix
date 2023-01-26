#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mm;
    for (int i = 0; i < s.length(); i++) {
      mm[s[i]]++;
    }
    int cd = 0, sd = 0;
    for (auto i = mm.begin(); i != mm.end(); i++) {
      if (mm[i->first] >= 2)
        cd++;
      else
        sd++;
    }
    int tc = 0;
    tc = cd + (sd / 2);
    cout << tc << endl;
  }
  return 0;
}
