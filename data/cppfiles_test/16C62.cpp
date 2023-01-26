#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 3e5 + 5;
using namespace std;
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> ans;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> num;
      pq.emplace(num, i + 1);
    }
    while (pq.size() >= 2) {
      int frst = pq.top().first;
      int frst_indx = pq.top().second;
      pq.pop();
      int scnd = pq.top().first;
      int scnd_indx = pq.top().second;
      pq.pop();
      if (frst >= 1 && scnd >= 1) {
        ans.emplace_back(frst_indx, scnd_indx);
        frst--;
        scnd--;
      }
      if (frst >= 1) {
        pq.emplace(frst, frst_indx);
      }
      if (scnd >= 1) {
        pq.emplace(scnd, scnd_indx);
      }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
      cout << x.second << " " << x.first << "\n";
    }
  }
  return 0;
}
