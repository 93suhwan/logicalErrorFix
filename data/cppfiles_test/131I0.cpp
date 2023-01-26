#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
map<int, pair<pair<int, int>, pair<int, int> > > mp;
int f(int x) {
  int res = 1;
  while (res < x) res <<= 1;
  return res - x;
}
void cg(int x, pair<int, int> send) {
  if (mp[x].first < send) {
    mp[x].second = mp[x].first;
    mp[x].first = send;
  } else if (mp[x].second < send) {
    mp[x].second = send;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    q.push(x);
    mp[x].first = {0, i};
  }
  while (q.size()) {
    int x = q.top();
    q.pop();
    if (x == 0) continue;
    if (!q.empty() && q.top() == x) q.pop();
    int fx = f(x);
    q.push(fx);
    pair<int, int> send = mp[x].first;
    send.first++;
    cg(fx, send);
  }
  int ra, rb, rc = -1;
  for (auto &x : mp) {
    pair<pair<int, int>, pair<int, int> > v = x.second;
    if (v.first.second == 0 || v.second.second == 0) continue;
    if (rc < v.first.first + v.second.first) {
      rc = v.first.first + v.second.first;
      ra = v.first.second;
      rb = v.second.second;
    }
  }
  cout << ra << " " << rb << " " << rc << endl;
}
