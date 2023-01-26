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
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  vector<pair<pair<long long, long long>, long long>> Ans;
  sort(b, b + n);
  auto issort = [&](long long *a, long long n) {
    for (long long i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) return 0;
    }
    return 1;
  };
  for (long long i = 0; i < n and !issort(a, n); i++) {
    long long l = i, j = 0;
    if (a[i] == b[i]) continue;
    for (j = i + 1; j < n; j++) {
      if (a[j] == b[i]) break;
    }
    if (i == j) continue;
    Ans.push_back({{l + 1, j + 1}, j - i});
    long long temp = a[j];
    for (long long k = j; k > l; k--) a[k] = a[k - 1];
    a[l] = temp;
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
