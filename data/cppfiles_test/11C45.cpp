#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
const int MOD = 1000000007;
const int MX = 100001;
int main() {
  int n;
  cin >> n;
  vii v;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i >= x) v.push_back(ii(i + 1 - x, x));
  }
  sort(v.begin(), v.end());
  vi s;
  for (auto i : v) {
    auto it = lower_bound(s.begin(), s.end(), i.second);
    if (it == s.end())
      s.push_back(i.second);
    else
      *it = i.second;
  }
  cout << (int)s.size();
  return 0;
}
