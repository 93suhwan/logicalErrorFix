#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i, j;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long int sum = 0;
    n = str.size();
    map<char, long long int> mapp;
    deque<char> v;
    for (i = 0; i < str.length(); i++) {
      mapp[str[i]]++;
      auto a1 = lower_bound(v.begin(), v.end(), str[i]);
      auto b1 = upper_bound(v.begin(), v.end(), str[i]);
      if (a1 == b1) {
        v.push_back(str[i]);
      } else {
        if (a1 == b1 - 1) {
          v.push_back(str[i]);
        }
      }
    }
    long long int ans = v.size();
    cout << ans / 2 << endl;
  }
}
