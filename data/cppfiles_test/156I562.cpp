#include <bits/stdc++.h>
using namespace std;
vector<long long> chk;
long long k;
void solve() {
  long long n;
  cin >> n >> k;
  long long a;
  long long su = 0;
  chk.clear();
  for (int i = 0; i < n; i++) {
    cin >> a;
    chk.push_back(a);
    su += a;
  }
  sort(chk.begin(), chk.end());
  long long ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      su -= chk[chk.size() - i] - chk[0];
    }
    long long kilk = su - k;
    if (kilk % (i + 1) == 0) {
      ans = min(ans, max((long long)0, i + kilk / (i + 1)));
    } else {
      ans = min(ans, max((long long)0, i + kilk / (i + 1)));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
