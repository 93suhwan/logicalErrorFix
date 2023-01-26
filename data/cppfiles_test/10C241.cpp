#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
long long cei(long long a, long long b) {
  long long val = (a / b) + ((a % b) != 0);
  return val;
}
vector<vector<int>> countArr(200001);
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n + 1; i++) {
    countArr[i].clear();
  }
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<long long> st;
  for (long long i = 0; i < n; i++) {
    st.insert(a[i]);
    countArr[a[i]].push_back(i);
  }
  map<int, int> cnt;
  for (long long i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  vector<long long> color(n, 0);
  long long ans = 0;
  vector<int> temp;
  for (auto x : st) {
    if (cnt[x] >= k) {
      ans++;
      for (int i = 0; i < k; i++) {
        color[countArr[x][i]] = i + 1;
      }
    }
    if (cnt[x] < k) {
      for (auto y : countArr[x]) temp.push_back(y);
    }
  }
  int curr = (int)((temp).size()) / k;
  curr = curr * k;
  ans += curr;
  int col = 1;
  for (int i = 1; i <= curr; i++) {
    if ((i - 1) % k == 0) col = 1;
    color[temp[i - 1]] = col;
    col++;
  }
  for (long long i = 0; i < n; i++) cout << color[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
