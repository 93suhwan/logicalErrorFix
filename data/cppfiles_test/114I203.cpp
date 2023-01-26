#include <bits/stdc++.h>
using namespace std;
long long int mult(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) * (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int add(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) + (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int subt(long long int a, long long int b) {
  long long int ans = ((a % int(1e9 + 7)) - (b % int(1e9 + 7))) % int(1e9 + 7);
  ans %= int(1e9 + 7);
  ans = (ans + int(1e9 + 7)) % int(1e9 + 7);
  return ans;
}
long long int exp(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    }
    po = ((po % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    b /= 2;
  }
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int>> slot;
  vector<multiset<long long int>> freq(n);
  vector<long long int> maxi(n, 0), max1;
  for (int i = 0; i < n; i++) {
    long long int c;
    cin >> c;
    vector<long long int> temp(c);
    for (long long int j = 0; j < c; j++) {
      cin >> temp[j];
      freq[i].insert(temp[j]);
      maxi[i] = max(maxi[i], temp[j]);
    }
    slot.push_back(temp);
  }
  long long int tot = 0;
  for (int i = 0; i < n; i++) {
    auto it = freq[i].end();
    it--;
    tot += (*it);
  }
  long long int m;
  cin >> m;
  vector<vector<long long int>> ban(m, vector<long long int>(n));
  for (int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> ban[i][j];
      if (freq[j].find(ban[i][j]) != freq[j].end()) {
        freq[j].erase(freq[j].find(ban[i][j]));
      }
    }
  }
  long long int ans = tot;
  long long int ind;
  for (int i = 0; i < n; i++) {
    if (freq[i].size() != 0) {
      auto it = freq[i].end();
      it--;
      if (tot - maxi[i] + (*it) <= ans) {
        ans = tot - maxi[i] + (*it);
        ind = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    long long int si;
    if (i == (ind)) {
      si = freq[i].size();
    } else {
      si = slot[i].size();
    }
    cout << si << " ";
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
