#include <bits/stdc++.h>
using namespace std;
int max(int x, int y) { return (x > y) ? x : y; }
int lps(char *seq, int i, int j) {
  if (i == j) return 1;
  if (seq[i] == seq[j] && i + 1 == j) return 2;
  if (seq[i] == seq[j]) return lps(seq, i + 1, j - 1) + 2;
  return max(lps(seq, i, j - 1), lps(seq, i + 1, j));
}
void solve() {
  long long n;
  cin >> n;
  char seq[n];
  map<char, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> seq[i];
    m[seq[i]]++;
  }
  long long maxi = 0;
  for (auto pr : m) {
    maxi = max(maxi, pr.second);
  }
  long long x = lps(seq, 0, n - 1);
  long long ans = (n - x);
  if (ans > maxi) {
    cout << "-1" << endl;
    return;
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
