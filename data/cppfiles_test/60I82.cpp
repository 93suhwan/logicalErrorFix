#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  map<int, int> freqs;
  long long int mean = 0;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    mean += el;
    v.push_back(el);
  }
  if (2 * mean % n != 0) {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    int el = v[i];
    if (freqs.count(el) > 0) {
      freqs[el]++;
    } else {
      freqs[el] = 1;
    }
  }
  double f_mean = (double)mean / n;
  int ans = 0;
  for (auto &x : freqs) {
    int targetNum = 2 * f_mean - x.first;
    if (targetNum == x.first) {
      ans += x.second * (x.second - 1);
    } else {
      if (freqs.count(targetNum) > 0) {
        ans += freqs[targetNum] * x.second;
      }
    }
  }
  cout << ans / 2 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
