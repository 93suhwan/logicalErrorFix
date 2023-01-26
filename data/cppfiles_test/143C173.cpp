#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<long long> cnt(n + 1, 0);
  vector<long long> res(n + 1, -1);
  stack<long long> st;
  for (auto i : a) {
    cnt[i]++;
  }
  long long sum = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i <= n; i++) {
    if (i > 0 && cnt[i - 1] == 0) {
      if (st.empty()) break;
      long long k = st.top();
      st.pop();
      sum += i - k - 1;
    }
    res[i] = sum + cnt[i];
    while (i > 0 and cnt[i - 1] > 1) {
      cnt[i - 1]--;
      st.push(i - 1);
    }
  }
  for (auto i : res) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
