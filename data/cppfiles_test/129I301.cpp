#include <bits/stdc++.h>
using namespace std;
void solve(long long t) {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<int> vis(n + 1, 0);
  vector<int> index;
  vector<int> p;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= n)
      vis[arr[i]] = 1;
    else {
      p.push_back(arr[i]);
      index.push_back(i);
    }
  }
  sort(p.begin(), p.end());
  sort(index.begin(), index.end());
  long long res = 0;
  long long j = 0;
  for (int i = 0; i < p.size(); i++) {
    long long check2 = p[i] - index[i] - 1;
    if (check2 > 0 && p[i] % check2 == index[i] + 1) {
      res++;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << res << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve(t);
  }
}
