#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int mod(long long int a, long long int b) { return ((a % b) + b) % b; }
long long int MODnumber(long long int a) {
  return (a % (long long int)1000000007 + (long long int)1000000007) %
         (long long int)1000000007;
}
long long int MODsum(long long int a, long long int b) {
  return ((a % (long long int)1000000007 + b % (long long int)1000000007) %
              (long long int)1000000007 +
          (long long int)1000000007) %
         (long long int)1000000007;
}
long long int MODproduct(long long int a, long long int b) {
  return (((a % (long long int)1000000007) * (b % (long long int)1000000007)) %
              (long long int)1000000007 +
          (long long int)1000000007) %
         (long long int)1000000007;
}
void solve() {
  long long int n;
  cin >> n;
  map<long long int, long long int> difficulties;
  map<long long int, vector<long long int>> topicandDifficulty;
  for (long long int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    difficulties[y]++;
    topicandDifficulty[x].push_back(y);
  }
  long long int ans = 0;
  for (auto itr : topicandDifficulty) {
    long long int sz = itr.second.size();
    sz--;
    for (auto it : itr.second) {
      ans += sz * (difficulties[it] - 1);
    }
  }
  long long int countSame = 0;
  long long int countDiff = 0;
  for (auto it : difficulties) {
    countSame += (n - it.second) * (n - it.second - 1);
    countDiff += (it.second * (it.second - 1));
  }
  long long int temp = (n * (n - 1) * (n - 2)) / 6;
  temp -= ans;
  cout << temp << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
