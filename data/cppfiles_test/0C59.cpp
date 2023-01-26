#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 510, mod = 998244353, Mod = 1e9 + 7;
int n, m, k;
vector<string> q;
int cmp(string a, string b) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) continue;
    if (i & 1) {
      return a[i] > b[i];
    } else {
      return a[i] < b[i];
    }
  }
}
void solve() {
  cin >> n >> m;
  unordered_map<string, int> mp;
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    mp[x] = i;
    q.push_back(x);
  }
  sort(q.begin(), q.end(), cmp);
  for (int i = 0; i < n; i++) cout << mp[q[i]] << " ";
  cout << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t, Case = 1;
  { solve(); }
  return 0;
}
