#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
void printarr(long long arr[], long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
void asquare() {
  long long n, k, nn = 0, mm = 0, tt, x;
  cin >> n >> k;
  long long arr[n];
  long long ans[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unordered_map<long long, vector<long long>> ump;
  unordered_map<long long, long long> mmm;
  unordered_map<long long, vector<long long>> uv;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    ump[arr[i]].push_back(i);
  }
  long long index = 1, store;
  for (auto &a : ump) {
    if (a.second.size() >= k) {
      mm++;
      for (int i = 0; i < k; i++) {
        ans[a.second[i]] = index;
        index++;
        if (index == k + 1) index = 1;
      }
      for (int i = 0; i < a.second.size() - k; i++) ans[a.second[i + k]] = 0;
    } else {
      store = index;
      for (int i = 0; i < a.second.size(); i++) {
        ans[a.second[i]] = index;
        index++;
        if (index == k + 1) index = 1;
      }
      nn += a.second.size();
    }
  }
  tt = mm + nn / k;
  for (int i = 0; i < n; i++) {
    mmm[ans[i]]++;
    if (mmm[ans[i]] <= tt)
      cout << ans[i] << " ";
    else
      cout << "0 ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    asquare();
  }
  return 0;
}
