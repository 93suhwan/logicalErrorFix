#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int t = stoi(s);
  for (int k = 0; k < t; k++) {
    getline(cin, s);
    map<char, int> voc;
    for (int i = 0; i < s.length(); i++) {
      voc[s[i]]++;
    }
    int counter = 0;
    int counterOne = 0;
    for (auto now : voc) {
      if (now.second > 1) {
        counter += 2;
      }
      if (now.second == 1) {
        counterOne++;
      }
    }
    if (counterOne % 2 == 0) {
      counter += counterOne;
    } else {
      counter += counterOne;
      counter--;
    }
    cout << counter / 2 << "\n";
  }
  return 0;
}
