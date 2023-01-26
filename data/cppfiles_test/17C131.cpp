#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
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
void enumerateSubmasks(long long m) {
  for (long long s = m;; s = (s - 1) & m) {
    if (s == 0) {
      break;
    }
  }
}
long long mpow(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long x = mpow(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2) {
    x = (x * a) % m;
  }
  return x;
}
void printBinaryString(long long n) {
  vector<long long> temp;
  while (n) {
    if (n & 1)
      temp.push_back(1);
    else
      temp.push_back(0);
    n = n >> 1;
  }
  reverse(temp.begin(), temp.end());
  for (auto node : temp) cout << node << " ";
  cout << endl;
}
void readVector(vector<long long> &a) {
  long long n = a.size();
  for (long long i = 0; i < n; ++i) cin >> a[i];
}
long long solve(vector<long long> &arr, vector<long long> &mine, long long idx,
                map<long long, long long> &equalV) {
  if (idx == 0) return 0;
  long long v = min(mine[idx], (idx + 1) - equalV[arr[idx]] - mine[idx]);
  equalV[arr[idx]]--;
  v += solve(arr, mine, idx - 1, equalV);
  return v;
}
void update(vector<long long> &bit, long long n, long long idx) {
  while (idx <= n) {
    bit[idx]++;
    idx += (idx & -idx);
  }
}
long long query(vector<long long> &bit, long long idx) {
  long long answer = 0;
  while (idx > 0) {
    answer += bit[idx];
    idx -= (idx & (-idx));
  }
  return answer;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    readVector(arr);
    long long idx = 1;
    set<long long> s;
    for (auto node : arr) s.insert(node);
    map<long long, long long> mapping;
    for (auto node : s) mapping[node] = idx++;
    for (long long i = 0; i < n; ++i) arr[i] = mapping[arr[i]];
    map<long long, long long> equalV;
    for (long long i = 0; i < n; ++i) equalV[arr[i]]++;
    vector<long long> mine(n);
    vector<long long> bit(200001, 0);
    for (long long i = 0; i < n; i++) {
      long long lessThan = query(bit, arr[i] - 1);
      mine[i] = lessThan;
      update(bit, 200000, arr[i]);
    }
    cout << solve(arr, mine, n - 1, equalV) << endl;
  }
}
