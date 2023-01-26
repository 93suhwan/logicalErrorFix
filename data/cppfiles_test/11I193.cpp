#include <bits/stdc++.h>
const long long int mod = 1e9 + 7;
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
bool sortdec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
void solve() {
  int n;
  cin >> n;
  vector<vector<pair<long long int, int>>> v;
  for (int i = (0); i < (5); i++)
    v.push_back(vector<pair<long long int, int>>());
  long long int len[n];
  for (int i = (0); i < (n); i++) {
    string word;
    cin >> word;
    len[i] = word.length();
    long long int freq[5];
    memset(freq, 0, sizeof(freq));
    for (int j = (0); j < (word.length()); j++) {
      int idx = word[j] - 'a';
      freq[idx] += 1;
    }
    for (int j = (0); j < (5); j++) v[j].push_back(make_pair(freq[j], i));
  }
  long long int ans = 0;
  for (int i = (0); i < (5); i++) {
    long long int maxLen = 0;
    long long int prevSum = 0;
    long long int otherSum = 0;
    sort(v[i].begin(), v[i].end(), sortdec);
    for (int j = (0); j < (n); j++) {
      if (v[i][j].first + prevSum >
          otherSum + len[v[i][j].second] - v[i][j].first) {
        prevSum += v[i][j].first;
        otherSum += len[v[i][j].second] - v[i][j].first;
        maxLen++;
      }
    }
    ans = max(ans, maxLen);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
