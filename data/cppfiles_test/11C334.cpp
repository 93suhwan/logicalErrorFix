#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
int solve2(const vector<string> &vec, char c) {
  int n = vec.size();
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    int bal = 0;
    for (char ch : vec[i]) {
      if (ch == c) {
        bal++;
      } else {
        bal--;
      }
    }
    val[i] = bal;
  }
  int t = 0, cur = 0;
  sort((val).begin(), (val).end(), greater<int>());
  for (int i = 0; i < n; i++) {
    if (val[i] > 0 || cur + val[i] > 0) {
      cur += val[i];
      t++;
    }
  }
  return t;
}
void solve() {
  int n;
  cin >> n;
  vector<string> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  int ans = 0;
  for (char i = 'a'; i <= 'e'; i++) {
    ans = max(ans, solve2(vec, i));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
