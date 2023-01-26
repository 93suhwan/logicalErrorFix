#include <bits/stdc++.h>
using namespace std;
void fileioe() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
}
const long long mod = 1000000007;
const long long INF = 1e18;
const long long MAX = 100001;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  vector<pair<long long, long long>> vec;
  map<long long, vector<long long>> m;
  vec.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    vec.push_back({arr[i], i});
    m[arr[i]].push_back(i);
  }
  vector<long long> an(n, 0);
  long long sum = 0;
  for (auto itr : m) {
    long long y = itr.second.size();
    sum += min(y, k);
  }
  long long ans = sum / k;
  sort(vec.begin(), vec.end());
  long long ctr = 1, p = 1;
  map<int, set<int>> m1;
  for (int i = 1; i <= n; i++) {
    if (ctr <= k) {
      if (m1[vec[i].first].count(ctr)) continue;
      an[vec[i].second] = ctr;
      m1[vec[i].first].insert(ctr);
      if (ctr == k) ans--;
    } else {
      ctr = 1;
      if (m1[vec[i].first].count(1)) continue;
      an[vec[i].second] = 1;
      m1[vec[i].first].insert(1);
    }
    if (ans == 0) break;
    ctr++;
  }
  for (auto itr : an) cout << itr << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
