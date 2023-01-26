#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
string second;
void num_to_str(int num) {
  if (num) {
    num_to_str((num - 1) / 26);
    second += ('a' + (num - 1) % 26);
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, k = 0, d = 0, f = 0, a, b, c = 0, j = 0, ans = 0;
    string s;
    cin >> s;
    long long l = s.size();
    map<char, long long> mp;
    sort(s.begin(), s.end());
    for (i = 0; i < l; i++) {
      mp[s[i]]++;
      if (mp[s[i]] == 3) mp[s[i]]--;
    }
    for (auto it : mp) {
      d += it.second;
    }
    cout << d / 2 << endl;
  }
}
