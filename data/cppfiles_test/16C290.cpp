#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    std::vector<long long> v(n);
    priority_queue<pair<long long, long long>> pq;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i]) {
        pq.push({v[i], i});
      }
    }
    vector<pair<long long, long long>> ans;
    while (pq.size() > 1) {
      long long num1 = pq.top().first;
      long long ind1 = pq.top().second + 1;
      pq.pop();
      long long num2 = pq.top().first;
      long long ind2 = pq.top().second + 1;
      pq.pop();
      num1--;
      num2--;
      ans.push_back({ind1, ind2});
      if (num1 > 0) {
        pq.push({num1, ind1 - 1});
      }
      if (num2 > 0) {
        pq.push({num2, ind2 - 1});
      }
    }
    cout << ans.size() << '\n';
    for (auto itr : ans) {
      cout << itr.first << " ";
      cout << itr.second << " ";
      cout << "\n";
    }
  }
  return 0;
}
