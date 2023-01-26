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
    int total = s.length() / 2;
    for (auto it : freq) total -= it.second / 3;
    cout << total << endl;
  }
}
