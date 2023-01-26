#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int M = 998244353;
long long int power(long long int b, long long int p) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    return (b * power(b, p - 1)) % M;
  } else {
    return (power((b * b) % M, p / 2)) % M;
  }
}
bool check(int ind, int k, vector<int> edges[], int p, int& c) {
  bool ans = true;
  int C = 0;
  for (auto e : edges[ind]) {
    if (e == p) continue;
    ans &= check(e, k, edges, ind, C);
    if (!ans) return false;
  }
  if (p != -1) {
    if (C % k == 0) {
      c++;
      return true;
    } else {
      C++;
      if (C % k == 0) {
        return true;
      }
    }
    return false;
  } else {
    if (C % k == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mpp;
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      mpp[a] = b;
      mpp[b] = a;
    }
    vector<int> rem;
    for (int i = 0; i < 2 * n; i++) {
      if (mpp.find(i) == mpp.end()) {
        rem.push_back(i);
      }
    }
    for (int i = 0; i < rem.size(); i++) {
      mpp[rem[i]] = rem[(i + rem.size() / 2) % rem.size()];
    }
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
      int f = i;
      int s = mpp[i];
      for (int j = f + 1; j < s; j++) {
        if (mpp[j] < f || mpp[j] > s) {
          ans++;
        }
      }
    }
    ans /= 2;
    cout << ans << endl;
  }
  return 0;
}
