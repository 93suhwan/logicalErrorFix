#include <bits/stdc++.h>
using namespace std;
int tc;
string s;
map<char, int> cnt, tmp;
bool can(int x) {
  tmp.clear();
  int a = 0, b = 0;
  for (auto &i : cnt) {
    if (!i.second || a == x) continue;
    tmp[i.first]++;
    i.second--;
    a++;
  }
  for (auto &i : cnt) {
    if (!i.second || b == x) continue;
    tmp[i.first]++;
    i.second--;
    b++;
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
