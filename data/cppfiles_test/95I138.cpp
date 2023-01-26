#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s = to_string(n);
    int m = s.length();
    int l = 1;
    vector<int> v;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < s[i] - '0'; j++) {
        v.push_back(l);
      }
      l = 10 * l;
    }
    if (v.size() >= k) {
      for (int i = 0; i < k - 1; i++) cout << v[i] << " ";
      int sum = 0;
      for (int i = k - 1; i < v.size(); i++) sum += v[i];
      cout << sum << endl;
    } else {
      priority_queue<int> pq;
      for (auto it : v) pq.push(it);
      while (pq.size() < k) {
        int x = pq.top();
        pq.pop();
        string s1 = to_string(x);
        if (s1[0] == '1') {
          int y = s1.length() - 2;
          int l = (int)(pow(10, y) + 0.001);
          for (int j = 0; j < 10; j++) pq.push(l);
        }
      }
      vector<int> v1;
      while (pq.size()) {
        v1.push_back(pq.top());
        pq.pop();
      }
      reverse(v1.begin(), v1.end());
      for (int i = 0; i < k - 1; i++) cout << v1[i] << " ";
      int sum = 0;
      for (int i = k - 1; i < v1.size(); i++) sum += v1[i];
      cout << sum << endl;
    }
  }
}
