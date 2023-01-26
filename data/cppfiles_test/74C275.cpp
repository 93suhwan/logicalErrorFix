#include <bits/stdc++.h>
using namespace std;
void solve(long long a, long long b) {
  long long total_matches = (a + b);
  long long mid1 = total_matches / 2;
  long long mid2 = total_matches - mid1;
  set<long long> s;
  for (long long i = 0; i <= min(a, mid1); i++) {
    long long matches_a_win = i;
    long long breaks_by_a = mid1 - i;
    long long match_to_be_won_by_a = a - i;
    long long breaks_by_b = match_to_be_won_by_a;
    if (breaks_by_b > mid2) continue;
    s.insert(breaks_by_a + breaks_by_b);
  }
  for (long long i = 0; i <= min(a, mid2); i++) {
    long long matches_a_win = i;
    long long breaks_by_a = mid2 - i;
    long long match_to_be_won_by_a = a - i;
    long long breaks_by_b = match_to_be_won_by_a;
    if (breaks_by_b > mid1) continue;
    s.insert(breaks_by_a + breaks_by_b);
  }
  cout << s.size() << endl;
  for (auto elements : s) cout << elements << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    solve(a, b);
  }
  return 0;
}
