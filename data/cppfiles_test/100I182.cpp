#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int n;
  vector<long long> a;
  while (t > 0) {
    cin >> n;
    int tmp;
    long long maxN;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }
    if (n == 1) {
      cout << tmp << endl;
      t--;
      continue;
    }
    sort(a.begin(), a.end());
    maxN = a[0];
    for (int i = 1; i < n; i++) {
      maxN = max(maxN, a[i] - a[i - 1]);
    }
    cout << maxN << endl;
    a.clear();
    t--;
  }
  return 0;
}
