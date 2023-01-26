#include <bits/stdc++.h>
using namespace std;
bool cmp(string x, string y) {
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] < y[i] && i & 1) {
      return x > y;
    }
    if (x[i] < y[i] && !(i & 1)) {
      return x < y;
    }
    if (x[i] > y[i] && i & 1) {
      return x > y;
    }
    if (x[i] > y[i] && !(i & 1)) {
      return x < y;
    }
  }
  return x < y;
}
int main() {
  int n, m;
  vector<string> vec;
  map<string, int> mp;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    vec.emplace_back(x);
    mp[x] = i + 1;
  }
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < n; ++i) {
    cout << mp[vec[i]] << endl;
  }
  return 0;
}
