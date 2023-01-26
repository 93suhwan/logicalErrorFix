#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string keys;
    string word;
    cin >> keys;
    cin >> word;
    map<char, int> mp;
    int i = 1;
    for (char x : keys) {
      mp[x] = i++;
    }
    int sum = 0;
    for (int i = 0; i < word.size() - 1; i++) {
      int diff = abs(mp[word[i]] - mp[word[i + 1]]);
      sum += diff;
    }
    cout << sum << endl;
  }
}
