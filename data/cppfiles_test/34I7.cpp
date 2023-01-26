#include <bits/stdc++.h>
using namespace std;
const int Max_value = 5000;
const int N = 1e6 + 10;
vector<int> g[Max_value + 10];
int ans[Max_value * 2];
int a[N];
int r[Max_value + 10];
vector<int> vec;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= Max_value; ++i) {
    g[i].push_back(0);
    r[i] = Max_value;
  }
  ans[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j : g[a[i]]) {
      int to = j ^ a[i];
      ans[to] = 1;
      for (int k = a[i] + 1; k <= r[to]; ++k) {
        g[k].push_back(to);
      }
      if (r[to] > a[i]) r[to] = a[i];
    }
    g[a[i]] = {};
  }
  for (int i = 0; i <= Max_value; ++i) {
    if (ans[i]) {
      vec.push_back(i);
    }
  }
  cout << vec.size() << endl;
  if (!vec.empty())
    for (auto i : vec) {
      cout << i << " ";
    }
  return 0;
}
