#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp1;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (mp1.find(s[i]) == mp1.end()) {
        mp1.insert({s[i], 1});
      } else {
        mp1[s[i]]++;
      }
    }
    unordered_map<char, int>::iterator mp2;
    for (mp2 = mp1.begin(); mp2 != mp1.end(); mp2++) {
      if (mp2->second > 1) {
        count1++;
      } else {
        count2++;
      }
    }
    count2 = count1 + (count2) / 2;
    cout << count2 << endl;
  }
  return 0;
}
