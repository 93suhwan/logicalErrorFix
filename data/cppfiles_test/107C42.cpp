#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long max_n = 100005;
long long arr[max_n];
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a + b > n - 2) {
    cout << -1 << "\n";
    return;
  }
  if (a == b + 1) {
    for (long long i = 1; i <= b + 1; i++) {
      arr[i * 2 - 1] = i + n - (2 * b + 2);
      arr[i * 2] = arr[i * 2 - 1] + (b + 1);
    }
    for (long long i = 2 * (b + 1) + 1; i <= n; i++) arr[i] = (n + 1) - i;
  } else if (a == b) {
    for (long long i = 1; i <= b; i++) {
      arr[i * 2 - 1] = i + b + n - (2 * b + 1);
      arr[i * 2] = i + n - (2 * b + 1);
    }
    arr[2 * b + 1] = n;
    for (long long i = 2 * b + 2; i <= n; i++) arr[i] = (n + 1) - i;
  } else if (a + 1 == b) {
    swap(a, b);
    for (long long i = 1; i <= b + 1; i++) {
      arr[i * 2 - 1] = i + n - (2 * b + 2);
      arr[i * 2] = arr[i * 2 - 1] + (b + 1);
    }
    for (long long i = 2 * (b + 1) + 1; i <= n; i++) arr[i] = (n + 1) - i;
    for (long long i = 1; i <= n; i++) arr[i] = (n + 1) - arr[i];
    swap(a, b);
  } else {
    cout << -1 << "\n";
    return;
  }
  long long cnt_a = 0, cnt_b = 0;
  for (long long i = 2; i < n; i++) {
    if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
      cnt_b++;
    else if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
      cnt_a++;
  }
  assert(cnt_a == a);
  assert(cnt_b == b);
  for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
