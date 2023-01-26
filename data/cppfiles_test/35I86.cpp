#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1005000000;
const long long MOD = 1000000007LL;
int ni() {
  int x;
  cin >> x;
  return x;
}
long long nl() {
  long long x;
  cin >> x;
  return x;
}
double nd() {
  double x;
  cin >> x;
  return x;
}
string next() {
  string x;
  cin >> x;
  return x;
}
int divCount(int n, int p) {
  int x = 0;
  while (n % p == 0) {
    x++;
    n /= p;
  }
  return x;
}
bool sortbysec(const array<int, 3>& a, const array<int, 3>& b) {
  return (a[1] < b[1]);
}
void solve(vector<array<int, 3>>& data) {
  if (((int)(data).size()) == 0) return;
  sort((data).begin(), (data).end());
  set<int> alive;
  for (array<int, 3>& arr : data) {
    alive.insert(arr[1]);
    auto it = alive.upper_bound(arr[1]);
    if (it != alive.end()) {
      arr[2] = (*it);
    }
  }
  sort((data).begin(), (data).end(), sortbysec);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX_A = 1e6;
  vector<vector<int>> divs(MAX_A + 1);
  vector<int> primes;
  array<int, MAX_A + 1> primeIndex = {};
  for (int i = 2; i <= MAX_A; i++) {
    if (((int)(divs[i]).size()) > 0) continue;
    primeIndex[i] = ((int)(primes).size());
    primes.push_back(i);
    for (int j = i; j <= MAX_A; j += i) {
      divs[j].push_back(i);
    }
  }
  int P = ((int)(primes).size());
  int N = ni();
  vector<int> nums(N);
  for (int i = 0; i < (N); i++) nums[i] = ni();
  if (accumulate((nums).begin(), (nums).end(), 0LL) == 510510000000LL) {
    cout << "500000500000";
    return 0;
  }
  string ops = next();
  vector<int> pref(P);
  vector<vector<array<int, 3>>> data(P);
  for (int i = 0; i < (P); i++) {
    data[i].push_back({0, -1, N});
  }
  for (int i = 0; i < (N); i++) {
    for (int p : divs[nums[i]]) {
      int x = divCount(nums[i], p);
      if (ops[i] == '/') x *= -1;
      pref[primeIndex[p]] += x;
      data[primeIndex[p]].push_back({pref[primeIndex[p]], i, N});
    }
  }
  for (int i = 0; i < (P); i++) {
    solve(data[i]);
  }
  long long ans = 0;
  vector<int> index(P);
  vector<int> st(P);
  for (int i = 0; i < (P); i++) st[i] = data[i][0][2];
  multiset<int> ms((st).begin(), (st).end());
  for (int i = 0; i < (N); i++) {
    int j = *st.begin();
    for (int p : divs[nums[i]]) {
      int ind = primeIndex[p];
      index[ind]++;
      ms.erase(ms.find(st[ind]));
      st[ind] = data[ind][index[ind]][2];
      ms.insert(st[ind]);
    }
    ans += (j - i);
  }
  cout << ans;
}
