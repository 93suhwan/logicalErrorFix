#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  vector<vector<long long>> v(500007);
  long long arr[500007];
  long long i = 0;
  while (t--) {
    long long a;
    cin >> a;
    if (a == 1) {
      long long x;
      cin >> x;
      v[x].push_back(i);
      i++;
    } else {
      long long x, y;
      cin >> x >> y;
      if (x != y) {
        if (v[x].size() > v[y].size()) v[x].swap(v[y]);
        v[y].insert(v[y].end(), v[x].begin(), v[x].end());
        v[x].clear();
      }
    }
  }
  for (long long j = 1; j <= 500007; j++) {
    if (!v[j].empty()) {
      for (auto child : v[j]) {
        arr[child] = j;
      }
    }
  }
  for (int j = 0; j < i; j++) cout << arr[j] << " ";
  cout << endl;
}
