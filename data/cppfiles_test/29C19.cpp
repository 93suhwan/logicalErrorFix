#include <bits/stdc++.h>
using namespace std;
int MAX = 1e6 + 100;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long cnt0 = 0, cnt1 = 0;
    while (n--) {
      int x;
      cin >> x;
      if (x == 0)
        cnt0++;
      else if (x == 1)
        cnt1++;
    }
    long long sum = 1;
    for (int i = 0; i < cnt0; ++i) {
      sum *= 2;
    }
    cout << sum * cnt1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
