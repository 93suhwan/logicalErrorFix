#include <bits/stdc++.h>
using namespace std;
int findAns(string inp) {
  unordered_map<char, int> mp;
  for (char ch : inp) {
    mp[ch]++;
  }
  int red = 0;
  int green = 0;
  for (auto itr : mp) {
    if (itr.second >= 2) {
      red++;
      green++;
    } else {
      if (red > green) {
        green++;
      } else {
        red++;
      }
    }
  }
  return min(red, green);
}
int main() {
  int tt;
  int n, ans;
  string inp;
  cin >> tt;
  while (tt--) {
    cin >> inp;
    cout << findAns(inp) << "\n";
  }
  return 0;
}
