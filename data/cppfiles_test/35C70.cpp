#include <bits/stdc++.h>
using namespace std;
const int m = 1000001;
int n;
int a[m];
vector<int> b[m], v[m];
stack<int> second;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < m; i++) {
    if (b[i].empty()) {
      for (long long j = i; j < m; j *= i) {
        for (long long l = j; l < m; l += j) {
          b[l].push_back(i);
        }
      }
    }
  }
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    second.push(i);
    for (int j : b[a[i]]) {
      if (c == '*') {
        v[j].push_back(i);
      } else {
        while (!second.empty() &&
               (v[j].empty() ? 1 : second.top() > v[j].back())) {
          second.pop();
        }
        if (!v[j].empty()) v[j].pop_back();
      }
    }
    ret += second.size();
  }
  cout << ret << '\n';
  return 0;
}
