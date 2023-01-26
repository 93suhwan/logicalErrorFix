#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int K = 2005;
const long long MOD = int(1e9) + 7;
const int INF = int(1e9) + 5;
const long long INF64 = 2e18;
inline long long add(long long a, long long b, long long m) {
  return (((a % m + b % m) % m + m) % m);
}
inline long long mul(long long a, long long b, long long m) {
  return (((a % m * b % m) % m + m) % m);
}
vector<pair<int, int> > segs;
int occ[N];
void recur(int cl, int cr) {
  if (cl == cr) {
    cout << cl << " " << cl << " " << cl << '\n';
    return;
  }
  for (int j = cl; j <= cr; j++) occ[j] = 0;
  vector<pair<int, int> > temp;
  for (auto ppp : segs) {
    int l = ppp.first;
    int r = ppp.second;
    if (l >= cl && r <= cr) {
      if (l == cl && r == cr) continue;
      temp.push_back({l, r});
    }
  }
  if (int((temp).size()) == 0) return;
  int m = int((temp).size()), i = 0;
  int ans1l = -1, ans1r = -1;
  int ans2l = -1, ans2r = -1;
  int mnl = temp[i].first;
  int mxr = temp[i].second;
  i++;
  while (i < m && temp[i].first <= mxr) {
    mxr = max(mxr, temp[i].second);
    i++;
  }
  ans1l = mnl;
  ans1r = mxr;
  for (int j = mnl; j <= mxr; j++) occ[j] = 1;
  if (i < int((temp).size())) {
    mnl = temp[i].first;
    mxr = temp[i].second;
    i++;
    while (i < m && temp[i].first <= mxr) {
      mxr = max(mxr, temp[i].second);
      i++;
    }
    ans2l = mnl;
    ans2r = mxr;
    for (int j = mnl; j <= mxr; j++) occ[j] = 1;
  }
  int d;
  for (int j = cl; j <= cr; j++) {
    if (occ[j] == 0) {
      d = j;
      break;
    }
  }
  cout << cl << " " << cr << " " << d << '\n';
  recur(ans1l, ans1r);
  if (ans2l != -1) {
    recur(ans2l, ans2r);
  }
}
void solve() {
  segs.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == n) continue;
    int len = r - l + 1;
    segs.push_back({l, r});
  }
  sort(segs.begin(), segs.end());
  recur(1, n);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
