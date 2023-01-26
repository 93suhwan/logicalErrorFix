#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<multiset<int>> now(2);
  multiset<int> rem(a.begin(), a.end());
  vector<long long> sum(2, 0);
  for (int i = 0; i < n; i++) {
    int x = *prev(rem.end());
    rem.erase(prev(rem.end()));
  }
}
