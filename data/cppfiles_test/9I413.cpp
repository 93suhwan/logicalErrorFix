#include <bits/stdc++.h>
using namespace std;
int tc;
string s;
map<char, int> cnt;
bool can(int x) {
  map<char, int> tmp;
  int a = 0, b = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    if (cnt[i] && a < x) {
      cnt[i]--;
      tmp[i]++;
      a++;
    }
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if (cnt[i] && b < x) {
      cnt[i]--;
      tmp[i]++;
      b++;
    }
  }
  for (auto i : tmp) cnt[i.first] += i.second;
  return a == x && b == x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> s;
    int ans = 0;
    cnt.clear();
    for (char i : s) cnt[i]++;
    for (int i = 26; i >= 1; i--) {
      if (can(i)) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
