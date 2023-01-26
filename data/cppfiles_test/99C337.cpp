#include <bits/stdc++.h>
const int mod = (int)1e9 + 7;
const int mem = 1e5 + 10;
using namespace std;
vector<int> iiv(int n) {
  vector<int> x;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    x.push_back(y);
  }
  return x;
}
vector<long long> illv(long long n) {
  vector<long long> x;
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    x.push_back(y);
  }
  return x;
}
void div(vector<int> x) {
  for (auto i : x) cout << i << " ";
  cout << "\n";
}
void dllv(vector<long long> x) {
  for (auto i : x) cout << i << " ";
  cout << "\n";
}
int dp[1000000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x, d;
    cin >> x >> d;
    long long tot = 0;
    long long lim = d % 4;
    long long cur = d - lim;
    cur++;
    for (long long i = cur; i <= d; i++) {
      if (x % 2 == 0) {
        x = x - i;
      } else
        x = x + i;
    }
    cout << x << "\n";
  }
}
