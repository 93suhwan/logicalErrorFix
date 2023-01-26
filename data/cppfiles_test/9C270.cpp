#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    string word;
    map<char, int> mymap;
    cin >> word;
    int count = 0;
    int frac = 0;
    for (int i = 0; i < word.length(); i++) {
      mymap[word[i]]++;
    }
    for (auto i : mymap) {
      if (i.second >= 2) {
        count++;
      } else {
        if (i.second == 1) {
          frac++;
        }
      }
    }
    cout << int(count) + frac / 2 << endl;
    t--;
  }
  return 0;
}
