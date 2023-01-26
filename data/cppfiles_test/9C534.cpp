#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> fq;
    for (int i = 0; i < s.size(); i++) {
      fq[s[i]]++;
    }
    int cnt = 0;
    for (auto z : fq) {
      if (z.second > 2) {
        cnt += 2;
      } else {
        cnt += z.second;
      }
    }
    cout << (cnt) / 2 << endl;
  }
  return 0;
}
