#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, maxi = INT_MIN;
    cin >> n;
    string arr[n];
    vector<int> domi;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (char i = 'a'; i <= 'e'; i++) {
      int pre = 0, others = 0;
      for (int i1 = 0; i1 < n; i1++) {
        for (int j = 0; j < arr[i1].size(); j++) {
          if (arr[i1][j] == i)
            pre++;
          else
            others++;
        }
        domi.push_back(pre - others);
        pre = 0, others = 0;
      }
      sort(domi.begin(), domi.end(), greater<int>());
      int cnt = 0, sum = 0;
      for (int i1 = 0; i1 < domi.size(); i1++) {
        sum += domi[i1];
        if (sum <= 0) break;
        cnt++;
      }
      domi.clear();
      maxi = max(maxi, cnt);
    }
    cout << maxi << endl;
  }
  return 0;
}
