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
  for (int i = (0); i < (n); i++) {
    string word;
    cin >> word;
    long long int freq[5];
    memset(freq, 0, sizeof(freq));
    for (int j = (0); j < (word.length()); j++) {
      int idx = word[j] - 'a';
      freq[idx] += 1;
    }
    for (int j = (0); j < (5); j++)
      v[j].push_back(make_pair(freq[j] - word.length() + freq[j], i));
  }
  long long int ans = 0;
  for (int i = (0); i < (5); i++) {
    sort(v[i].begin(), v[i].end(), sortdec);
    long long int prevSum = v[i][0].first;
    long long int len = 1;
    for (int j = 1; j < n && prevSum > 0; j++) {
      prevSum += v[i][j].first;
      len++;
    }
    if (prevSum <= 0) len--;
    ans = max(ans, len);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
