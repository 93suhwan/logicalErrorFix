#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  unordered_set<int> myNums;
  int mean = 0;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    mean += el;
    v.push_back(el);
    myNums.insert(el);
  }
  if (2 * mean % n != 0) {
    cout << "0\n";
    return;
  }
  double f_mean = (double)mean / n;
  int ans = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] + v[j] == 2 * f_mean) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
