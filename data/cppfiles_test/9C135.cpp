#include <bits/stdc++.h>
using namespace std;
void solve() {
  string word;
  cin >> word;
  map<char, int> omap;
  int len = word.length();
  for (int i = 0; i < len; i++) {
    omap[word[i]]++;
  }
  int sepasang = 0;
  int jomblo = 0;
  for (auto x : omap) {
    if (x.second >= 2) {
      sepasang++;
    } else if (x.second < 2) {
      jomblo++;
    }
  }
  int red = sepasang;
  red += jomblo / 2;
  cout << red << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
