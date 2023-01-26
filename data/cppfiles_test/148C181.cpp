#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
void solve() {
  long long w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<int> horD;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    horD.push_back(x);
  }
  cin >> n;
  vector<int> horU;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    horU.push_back(x);
  }
  cin >> n;
  vector<int> verL;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    verL.push_back(x);
  }
  cin >> n;
  vector<int> verR;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    verR.push_back(x);
  }
  long long mx = (horD[horD.size() - 1] - horD[0]) * h;
  mx = max(mx, (horU[horU.size() - 1] - horU[0]) * h);
  mx = max(mx, (verL[verL.size() - 1] - verL[0]) * w);
  mx = max(mx, (verR[verR.size() - 1] - verR[0]) * w);
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
