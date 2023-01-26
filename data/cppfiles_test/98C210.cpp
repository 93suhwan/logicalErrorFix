#include <bits/stdc++.h>
using namespace std;
void CharacterLonger(int tst) {
  for (int t = 1; t <= tst; t++) {
    string keyBoardString, word;
    cin >> keyBoardString >> word;
    int sum = 0;
    int position = 0;
    map<char, long long int> mapper;
    for (long long int i = 0; i < keyBoardString.size(); i++) {
      mapper[keyBoardString[i]] = i + 1;
    }
    for (int i = 1; i < word.size(); i++) {
      sum += abs(mapper[word[i - 1]] - mapper[word[i]]);
    }
    cout << sum << endl;
  }
}
int main() {
  int tst;
  cin >> tst;
  CharacterLonger(tst);
}
