#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INF64 = 1e18;
const int N = 1500000 + 10;
const int MOD = 1e9 + 7;
const double PI = acos(-1.);
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < int(t); ++q) {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < int(s.size()); ++i) cnt[s[i] - 'a']++;
    int uniq = 0;
    int pair = 0;
    for (int i = 0; i < int(26); ++i) {
      if (cnt[i] == 1)
        uniq++;
      else if (cnt[i] > 1)
        pair++;
    }
    cout << pair + uniq / 2 << '\n';
  }
}
