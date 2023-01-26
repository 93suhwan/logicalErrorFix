#include <bits/stdc++.h>
using namespace std;
int pow10(int x) {
  int ans = 1;
  for (int i = 0; i < x; i++) {
    ans *= 10;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s, n;
    cin >> s >> n;
    vector<int> d(10, 0);
    int pl = 0;
    int sum_dig = 0;
    while (s != 0) {
      d[pl] += (s % 10);
      sum_dig += (s % 10);
      s /= 10;
      pl++;
    }
    int dif = n - sum_dig;
    while (dif > 0) {
      for (int i = 1; i <= 9; i++) {
        if (d[i] > 0) {
          d[i]--;
          d[i - 1] += 10;
          dif -= 9;
          break;
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j < d[i]; j++) {
        ans.push_back(pow10(i));
      }
    }
    dif = -dif;
    while (dif > 0) {
      dif--;
      int ne = ans[ans.size() - 1] + ans[ans.size() - 2];
      ans.erase(ans.end() - 1);
      ans.erase(ans.end() - 1);
      ans.push_back(ne);
    }
    for (auto i : ans) cout << i << " ";
    cout << endl;
  }
}
