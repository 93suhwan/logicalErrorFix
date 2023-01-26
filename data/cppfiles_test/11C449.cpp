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
      int x = 0, y = 0;
      vector<int> vec;
      int all = 0;
      int temp = 0;
      for (auto e : s) {
        int gain = 0, lose = 0;
        for (auto itr : e)
          if (itr == i)
            gain++;
          else
            lose++;
        if (gain > lose)
          all += (gain - lose), temp++;
        else
          vec.push_back(lose - gain);
      }
      sort(vec.begin(), vec.end());
      for (auto e : vec) {
        if (all - e > 0) all -= e, temp++;
      }
      ans = max(ans, temp);
    }
    cout << ans << endl;
  }
  return 0;
}
