#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      freq[arr[i]] += 1;
    }
    vector<pair<int, int>> v;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++) {
      v.push_back({it->second, it->first});
    }
    sort(v.begin(), v.end());
    int k_copy = k;
    map<int, queue<int>> ans;
    vector<int> remaining;
    for (int i = 0; i < v.size(); i++) {
      int freqs = v[i].first;
      int num = v[i].second;
      if (freqs >= k) {
        queue<int> s;
        for (int j = 1; j <= k; j++) {
          s.push(j);
        }
        ans[num] = s;
      } else {
        for (int j = 0; j < freqs; j++) {
          remaining.push_back(num);
        }
      }
    }
    vector<int> temp;
    for (int i = 0; i < remaining.size(); i++) {
      if (temp.size() < k) {
        temp.push_back(remaining[i]);
      } else {
        for (int j = 0; j < k; j++) {
          if (ans.find(temp[j]) == ans.end()) {
            queue<int> s;
            s.push(j + 1);
            ans[temp[j]] = s;
          } else {
            ans[temp[j]].push(j + 1);
          }
        }
        temp.clear();
        temp.push_back(remaining[i]);
      }
    }
    if (temp.size() == k) {
      for (int j = 0; j < k; j++) {
        if (ans.find(temp[j]) == ans.end()) {
          queue<int> s;
          s.push(j + 1);
          ans[temp[j]] = s;
        } else {
          ans[temp[j]].push(j + 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans[arr[i]].empty()) {
        cout << 0 << " ";
      } else {
        cout << ans[arr[i]].front() << " ";
        ans[arr[i]].pop();
      }
    }
    cout << (char)(10);
  }
  return 0;
}
