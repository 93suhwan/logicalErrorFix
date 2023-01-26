#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (auto &zz : arr) cin >> zz;
  vector<long long> ans(501, 0);
  map<long long, unordered_set<long long>> mp;
  for (long long i = 0; i < n; i++) {
    ans[arr[i]] = 1;
    mp[arr[i]].insert(arr[i]);
    auto curr = mp.lower_bound(arr[i]);
    if (curr == mp.begin()) {
      continue;
    }
    curr = prev(curr);
    unordered_set<long long> &uns = (*curr).second;
    for (long long x : uns) {
      ans[(x ^ arr[i])] = 1;
      mp[arr[i]].insert((x ^ arr[i]));
      mp[arr[i]].insert(x);
    }
  }
  ans[0] = 1;
  vector<long long> final_ans;
  for (long long i = 0; i < 501; i++) {
    if (ans[i]) final_ans.push_back(i);
  }
  cout << final_ans.size() << "\n";
  for (auto zz : final_ans) cout << zz << " ";
  cout << "\n";
  return 0;
}
