#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++) {
      string x;
      cin >> x;
      s.push_back(x);
    }
    int ans = 0;
    for (char i = 'a'; i <= 'e'; i++) {
      vector<tuple<int, int>> vec;
      int x = 0, y = 0;
      for (auto e : s) {
        int gain = 0, lose = 0;
        for (auto itr : e)
          if (itr == i)
            gain++;
          else
            lose++;
        x += gain, y += lose;
        vec.emplace_back(lose * -1, gain);
      }
      sort(vec.begin(), vec.end());
      if (x > y)
        ans = n;
      else {
        int temp = n;
        for (auto e : vec) {
          x -= get<1>(e);
          y -= get<0>(e) * -1;
          temp--;
          if (x > y) break;
        }
        ans = max(temp, ans);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
