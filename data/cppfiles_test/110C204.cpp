#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
vector<int> v[maxn];
bool vis[maxn];
priority_queue<int, vector<int>, greater<int> > q1, q2;
int d[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      v[i].clear();
      vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> k;
      d[i] = k;
      if (k == 0) {
        q1.push(i);
      }
      while (k--) {
        cin >> x;
        v[x].push_back(i);
      }
    }
    int tmp;
    int cnt = 0;
    while (!q1.empty() || !q2.empty()) {
      cnt++;
      while (!q1.empty()) {
        tmp = q1.top();
        q1.pop();
        vis[tmp] = 1;
        for (int i = 0; i < v[tmp].size(); i++) {
          d[v[tmp][i]]--;
          if (d[v[tmp][i]] == 0) {
            if (v[tmp][i] > tmp)
              q1.push(v[tmp][i]);
            else
              q2.push(v[tmp][i]);
          }
        }
      }
      while (!q2.empty()) {
        tmp = q2.top();
        q2.pop();
        q1.push(tmp);
      }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      flag += vis[i];
    }
    if (flag == n)
      cout << cnt << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}
