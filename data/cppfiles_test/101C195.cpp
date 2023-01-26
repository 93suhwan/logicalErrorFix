#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "    ";
  err(++it, args...);
}
const int MOD = 1e9 + 7;
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
  vector<int> lev;
  for (auto &i : sY) lev.push_back(i);
  int l = 0;
  map<int, long long> mp;
  long long val = 0, ind = 0;
  while (l < ((int)(lev).size())) {
    long long cnt = 0, ck = lev[l];
    while (ind < ((int)(temp).size()) and temp[ind].second < ck) {
      cnt++;
      mp[temp[ind].first]++;
      ind++;
    }
    val += (cnt * (cnt - 1) / 2);
    for (auto &j : mp) {
      long long t = j.second;
      val -= (t * (t - 1) / 2);
    }
    l++;
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
  ;
  int tt;
  cin >> tt;
  while (tt--) solve();
}
