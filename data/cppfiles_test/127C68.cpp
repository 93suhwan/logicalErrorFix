#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    string s, t;
    cin >> s >> t;
    vector<int> ctr(26, 0);
    for (int i = 0; i < s.size(); i++) {
      ctr[s[i] - 'a']++;
    }
    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    if (t == "abc" && ctr[0] > 0) {
      swap(order[1], order[2]);
    }
    for (int c = 0; c < 26; c++) {
      for (int t = 0; t < ctr[order[c]]; t++) {
        cout << (char)(order[c] + 'a');
      }
    }
    cout << endl;
  }
  return 0;
}
