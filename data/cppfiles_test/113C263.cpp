#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  multiset<long long> heros;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    heros.insert(temp);
  }
  long long sum = accumulate(heros.begin(), heros.end(), 0LL);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long def, atk;
    cin >> def >> atk;
    long long min_gold = numeric_limits<long long>::max();
    auto it = heros.lower_bound(def);
    if (it != heros.end()) {
      min_gold = min(min_gold, max(0LL, atk - (sum - *it)));
    }
    if (it != heros.begin()) {
      it--;
      min_gold = min(min_gold, max(0LL, atk - (sum - *it)) + (def - *it));
    }
    cout << min_gold << '\n';
  }
  return 0;
}
