#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long test = 1; test <= t; test++) {
    long long n;
    cin >> n;
    vector<long long> ans(n, 0);
    auto query = [&](long long u, long long v, long long w) {
      long long res;
      cout << "? " << u + 1 << " " << v + 1 << " " << w + 1 << endl;
      cin >> res;
      return res;
    };
    vector<long long> queryWala(n, -1);
    int idx1p = -1, idx2p = -1;
    for (int i = 0; i < n; i += 3) {
      queryWala[i] = query(i, (i + 1) % n, (i + 2) % n);
      if (queryWala[i] == 0) {
        idx2p = i;
      } else
        idx1p = i;
    }
    vector<long long> temp1;
    for (int i = 0; i < 3; i++) {
      temp1.push_back(idx1p + i);
      temp1.push_back(idx2p + i);
    }
    sort(temp1.begin(), temp1.end());
    long long sze = temp1.size();
    for (int i = 0; i < sze; i++)
      if (queryWala[temp1[i]] == -1) {
        queryWala[temp1[i]] = query(temp1[i], (temp1[(i + 1) % sze]) % n,
                                    (temp1[(i + 2) % sze]) % n);
      }
    long long idx1 = -1, idx2 = -1;
    for (int i = 1; i < sze; i++)
      if (queryWala[temp1[i]] != queryWala[temp1[i - 1]]) {
        if (queryWala[temp1[i]] > queryWala[temp1[i - 1]]) {
          ans[temp1[(i + 2) % sze]] = 1;
          ans[temp1[i - 1]] = -1;
        } else {
          ans[temp1[(i + 2) % sze]] = -1;
          ans[temp1[i - 1]] = 1;
        }
        idx1 = temp1[(i + 2) % sze];
        idx2 = temp1[i - 1];
      }
    for (int i = 0; i < sze; i++)
      if (ans[i] == 0) {
        ans[i] = (query(i, idx1, idx2) ? 1 : -1);
      }
    long long cnt = 0;
    for (int i = 0; i < n; i++)
      if (ans[i] == -1) cnt++;
    cout << "! " << cnt << " ";
    for (int i = 0; i < n; i++)
      if (ans[i] == -1) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
