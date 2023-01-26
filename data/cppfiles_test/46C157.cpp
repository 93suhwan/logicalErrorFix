#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long t, n;
vector<long long> a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (auto& x : a) cin >> x;
    long long mini = a[n - 1], cnt = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] > mini) mini = a[i], cnt++;
    }
    cout << cnt << '\n';
  }
}
