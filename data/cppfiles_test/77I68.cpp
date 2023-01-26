#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> num;
vector<bool> flag;
long long x, y;
vector<long long> ans;
long long all;
long long bfs(long long s) {
  queue<long long> q;
  q.push(s);
  long long cnt = 0;
  long long k;
  while (q.size() > 0) {
    k = q.front();
    q.pop();
    flag[k] = 1;
    cnt++;
    for (long long i = 0; i < num[k].size(); i++) {
      if (flag[num[k][i]] == 0) {
        q.push(num[k][i]);
      }
    }
  }
  return cnt;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> y >> x;
  num.resize(x * y + 1);
  flag.resize(x * y + 1);
  long long k;
  for (long long i = 0; i < x * y; i++) {
    cin >> k;
    k = 15 - k;
    for (long long j = 0; j < 4; j++) {
      if (k & 1) {
        if (j == 0) num[i].push_back(i - 1);
        if (j == 1) num[i].push_back(i + x);
        if (j == 2) num[i].push_back(i + 1);
        if (j == 3) num[i].push_back(i - x);
        k--;
      }
      k /= 2;
    }
  }
  long long a;
  for (long long i = 0; i < x * y; i++) {
    if (flag[i] == 0) {
      a = bfs(i);
      ans.push_back(a);
    }
  }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
