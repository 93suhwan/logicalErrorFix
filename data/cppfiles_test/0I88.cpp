#include <bits/stdc++.h>
using namespace std;
bool comp(string s1, string s2) {
  bool flag = true;
  for (int i = 0; i < s1.length(); i++) {
    if (i % 2) {
      if (s2[i] > s1[i]) {
        flag = false;
        break;
      }
    } else {
      if (s1[i] > s2[i]) {
        flag = false;
        break;
      }
    }
  }
  return flag;
}
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mp[s[i]] = i + 1;
  }
  sort(s, s + n, comp);
  for (int i = 0; i < n; i++) {
    cout << mp[s[i]] << " ";
  }
}
