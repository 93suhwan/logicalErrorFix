#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    string word;
    map<char, int> mymap;
    cin >> word;
    float count = 0;
    for (int i = 0; i < word.length(); i++) {
      if (mymap[word[i]] > 2) {
        continue;
      }
      count += 0.5;
      mymap[word[i]]++;
    }
    cout << int(count) << endl;
    t--;
  }
  return 0;
}
