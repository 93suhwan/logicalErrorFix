#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    string s;
    map<char, int> mpp;
    int on = 0, to = 0;
    cin >> s;
    int l = s.size();
    for (int i = 0; i < l; i++) mpp[s[i]]++;
    for (auto it : mpp) {
      int kr = it.second;
      if (kr == 1)
        on++;
      else if (kr > 1)
        to++;
    }
    cout << (to + on / 2);
    puts(" ");
  }
  return 0;
}
