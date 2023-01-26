#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
clock_t timeStart, timeFinish;
void timeBegin() { timeStart = clock(); }
void timeEnd() { timeFinish = clock(); }
void timeDuration() {
  double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed << time_taken
       << setprecision(5);
  cout << " sec " << endl;
}
long long int n, h, a[105];
bool fun(long long int x) {
  long long int val = 0;
  for (int i = 0; i < n - 1; i++) {
    val += min(a[i + 1] - a[i], x);
  }
  val += x;
  if (val >= h) {
    return true;
  }
  return false;
}
void solve() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int l = 1, r = 1000000000000000000;
  long long int ans = r;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (fun(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
