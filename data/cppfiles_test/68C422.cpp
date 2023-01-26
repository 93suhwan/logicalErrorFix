#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;
const long long INF = 1e18;
bool sortby(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
void solve() {
  long long int k;
  cin >> k;
  long long int t = 1;
  while (t * t < k) {
    if (t * t == k) {
      cout << t << " " << 1 << "\n";
      return;
    }
    t++;
  }
  long long int sq = t * t;
  long long int c = sq - k;
  if (c < t) {
    cout << t << " " << (c + 1) << "\n";
  } else {
    cout << t - ((sq - t) - k) - 1 << " " << t << "\n";
  }
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
