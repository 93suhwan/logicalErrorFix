#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (auto it : s) freq[it]++;
    int total = s.length();
    for (auto it : freq)
      if (it.second >= 2) total -= (it.second - 2);
    cout << total / 2 << endl;
  }
}
