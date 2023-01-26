#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) return a.second < b.second;
  if (a.first == b.first) return false;
  return a.first < b.first;
}
long long fun(vector<pair<int, int>> &pos, set<int> &sY) {
  vector<pair<int, int>> temp;
  sY.insert(1e7);
  for (auto &i : pos) {
    if (sY.find(i.second) == sY.end()) temp.push_back(i);
  }
  sort(temp.begin(), temp.end(), comp);
  auto itr = sY.begin();
  map<int, long long> mp;
  long long val = 0, ind = 0, len = temp.size();
  while (itr != sY.end()) {
    long long cnt = 0, ck = *itr;
    while (ind < len and temp[ind].second < ck)
      cnt++, mp[temp[ind].first]++, ind++;
    val += (cnt * (cnt - 1) / 2);
    for (auto &j : mp) val -= (j.second * (j.second - 1) / 2);
    itr++;
    mp.clear();
  }
  return val;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  set<int> sX, sY;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sX.insert(x);
  }
  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;
    sY.insert(y);
  }
  vector<pair<int, int>> pos(k);
  for (int i = 0; i < k; i++) cin >> pos[i].first >> pos[i].second;
  long long ma = fun(pos, sY);
  for (int i = 0; i < k; i++) swap(pos[i].first, pos[i].second);
  long long mb = fun(pos, sX);
  cout << (ma + mb) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
