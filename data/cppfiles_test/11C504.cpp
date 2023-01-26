#include <bits/stdc++.h>
using namespace std;
bool comp(long long a, long long b) { return a > b; }
void solve() {
  long long m, n, k;
  cin >> n;
  vector<string> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  int over = 0;
  for (char ch = 'a'; ch <= 'e'; ch++) {
    vector<int> p;
    for (long long i = 0; i < n; i++) {
      m = arr[i].length();
      int count = 0;
      for (long long j = 0; j < m; j++) {
        if (arr[i][j] == ch) ++count;
      }
      p.push_back(2 * count - m);
    }
    sort(p.begin(), p.end(), comp);
    int sum = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
      if (sum + p[i] > 0) {
        sum += p[i];
        ans += 1;
      }
    }
    over = max(over, ans);
  }
  cout << over << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
