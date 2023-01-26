#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll greatest_common_divisor(ll a, ll b) {
  if (a % b == 0) return b;
  if (b % a == 0) return a;
  if (a > b) return greatest_common_divisor(a % b, b);
  return greatest_common_divisor(a, b % a);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  const int N = 1e5 + 5;
  vector<bool> seen(int(sqrt(N) + 3), false);
  vector<int> p;
  for (int i = 2; i < seen.size(); i++) {
    if (seen[i]) continue;
    p.push_back(i);
    seen[i] = true;
    for (int j = i * i; j < seen.size(); j += i) seen[j] = true;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool ans = true;
    unordered_map<int, int> map;
    for (int i = 1; i <= n; i++) {
      int cur = i + 1;
      for (auto x : p) {
        if (cur % x == 0) {
          int tmp_count = 0;
          while (cur % x == 0) {
            cur /= x;
            tmp_count++;
          }
          if (map.find(x) == map.end())
            map[x] = tmp_count;
          else
            map[x] = max(map[x], tmp_count);
          if (cur == 1) break;
        }
      }
      if (cur != 1)
        if (map.find(cur) == map.end()) map[cur] = 1;
      cur = a[i - 1];
      ans = false;
      for (auto x : map) {
        if (cur % x.first != 0) {
          ans = true;
          break;
        } else {
          int tmp_count = 0;
          while (tmp_count < x.second && cur % x.first == 0) {
            cur /= x.first;
            tmp_count++;
          }
          if (tmp_count < x.second) {
            ans = true;
            break;
          }
        }
      }
      if (ans == false) break;
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
