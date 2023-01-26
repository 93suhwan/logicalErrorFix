#include <bits/stdc++.h>
using namespace std;
long long t;
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  long long tmp[n + 1];
  map<int, int> mapp;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    tmp[i] = a[i];
    mapp[a[i]] = i;
  }
  sort(tmp + 1, tmp + 1 + n);
  long long res = 0;
  for (long long i = n; i >= 1; i--) {
    int maxindex = mapp.find(tmp[i])->second;
    if (a[maxindex] > maxindex) {
      res += (a[maxindex] - maxindex);
      if ((n + (a[maxindex] - maxindex)) >= a[maxindex]) break;
    }
  }
  cout << res << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
