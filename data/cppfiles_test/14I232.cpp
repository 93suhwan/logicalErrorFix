#include <bits/stdc++.h>
using namespace std;
template <typename T>
using prqueue = priority_queue<T>;
template <typename T>
using prqueues = priority_queue<T, vector<T>, greater<T>>;
const long long MOD = 1e9 + 7;
const unsigned long long INF = 1000000000000000000;
const long long N = 1e7 + 7;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<pair<long long, long long>, long long>> Ans;
  auto issort = [&](long long *a, long long n) {
    for (long long i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) return 0;
    }
    return 1;
  };
  long long cnt = 0;
  while (!issort(a, n) && cnt++ < n + 10) {
    long long l = 0;
    while (a[l] < a[l + 1] and l < n - 1) {
      l++;
    }
    long long r = l + 1;
    while (r < n - 1 and a[r] > a[r + 1]) r++;
    long long len = r - l + 1, offset = r - l, temp = a[r];
    for (long long i = l + 1; i <= r; i++) {
      a[i] = a[(i - 1)];
    }
    a[l] = temp;
    Ans.push_back({{l + 1, r + 1}, r - l});
  }
  cout << (int)(Ans).size() << "\n";
  for (auto i : Ans) {
    cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
