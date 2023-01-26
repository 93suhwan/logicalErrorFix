#include <bits/stdc++.h>
using namespace std;
int n, k, u, x;
long long msk = 0, ful;
vector<long long> ve = {0};
void sort_mask(vector<long long> &ve, long long msk) {
  for (long long &x : ve) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((msk >> i & 1) && (x >> i & 1)) {
        cnt++;
        x ^= (1LL << i);
      }
    }
    for (int i = n - 1; i >= 0 && cnt > 0; i--) {
      if (msk >> i & 1) {
        x ^= (1LL << i);
        cnt--;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  ful = (1LL << n) - 1;
  if (n == 1) {
    return cout << "ACCEPTED", 0;
  }
  while (k--) {
    cin >> u;
    long long cur = 0;
    while (u--) {
      cin >> x;
      cur ^= 1LL << (x - 1);
    }
    int sz = ve.size();
    for (long long lef = (ful ^ msk) & cur; lef > 0; lef -= lef & -lef) {
      for (int i = 0; i < sz; i++) {
        ve.push_back(ve[i] | lef);
      }
    }
    sort_mask(ve, cur);
  }
  sort(ve.begin(), ve.end());
  ve.erase(unique(ve.begin(), ve.end()), ve.end());
  if (msk != ful || ve.size() != n + 1) {
    return cout << "REJECTED", 0;
  }
  for (int i = 0; i <= n; i++) {
    long long cor = (~((1LL << (n - i)) - 1)) & ful;
    if (ve[i] != cor) {
      return cout << "REJECTED", 0;
    }
  }
  cout << "ACCEPTED";
}
