#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  vector<long long> v[10007];
  long long arr[10007];
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
      for (auto aq : v[x]) v[y].push_back(aq);
      v[x].clear();
    }
  }
  for (long long j = 1; j <= 1007; j++) {
    if (!v[j].empty()) {
      for (auto child : v[j]) {
        arr[child] = j;
      }
    }
  }
  for (int j = 0; j < i; j++) cout << arr[j] << " ";
  cout << endl;
}
