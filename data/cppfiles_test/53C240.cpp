#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> vec;
  unordered_map<long long int, long long int> umap;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    vec.push_back(x);
  }
  vector<long long int> dup;
  dup = vec;
  sort(dup.begin(), dup.end());
  for (long long int i = 0; i < n; i++) {
    umap[dup[i]] = i;
  }
  for (long long int i = 0; i < n - 1; i++) {
    long long int index = umap[vec[i]];
    long long int next;
    if (k == 0) {
      cout << "No" << endl;
      return;
    }
    if (index + 1 == n) {
      next = -1;
      k--;
    } else {
      if (dup[index + 1] == vec[i + 1]) {
      } else {
        k--;
      }
    }
  }
  if (k == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
