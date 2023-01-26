#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long int advceil(long long int num, long long int den) {
  return (num % den == 0 ? num / den : num / den + 1);
}
long long int lstbt(long long int val) {
  long long int msk = val & (val - 1);
  return log2(val ^ msk);
}
long long int modmul(long long int a, long long int b) {
  if (a < 1e9 and b < 1e9) return (a * b) % 1000000007;
  a %= 1000000007;
  b %= 1000000007;
  long long int res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % 1000000007;
    a = (a * 2) % 1000000007;
    b /= 2;
  }
  return res;
}
long long int modexpo(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = modmul(res, a);
    a = modmul(a, a);
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return a == 0 ? b : gcd(b % a, a);
}
vector<long long int> CALCfactor(long long int n) {
  vector<long long int> factor(n + 2, 0);
  for (long long int i = 4; i <= n; i += 2) factor[i] = 2;
  for (long long int j = 3; j <= n; j += 2) {
    if (factor[j]) continue;
    for (long long int i = 2 * j; i <= n; i += j) factor[i] = j;
  }
  return factor;
}
vector<long long int> CALCprimeNUM(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> primeNUM;
  primeNUM.reserve(n + 2);
  for (long long int i = 2; i <= n; i++)
    if (!factor[i]) primeNUM.push_back(i);
  return primeNUM;
}
vector<long long int> CALCprimeFACTOR(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> ans;
  while (factor[n] != 0) {
    ans.push_back(factor[n]);
    n /= factor[n];
  }
  if (n > 1) ans.push_back(n);
  return ans;
}
vector<long long int> unique(vector<long long int> x) {
  sort(x.begin(), x.end());
  set<long long int> s;
  vector<long long int> ans;
  ans.reserve(x.size() * 1ll);
  for (auto elem : x) s.insert(elem);
  for (auto elem : s) ans.push_back(elem);
  return ans;
}
pair<vector<long long int>, vector<long long int> > getFact(long long int n) {
  vector<long long int> fact(n + 1, 1), invfact(n + 1, 1);
  for (long long int i = 1; i <= n; i++)
    fact[i] = (i * (fact[i - 1])) % 1000000007;
  for (long long int i = 1; i <= n; i++)
    invfact[i] = (modexpo(i, 1000000007 - 2) * invfact[i - 1]) % 1000000007;
  return {fact, invfact};
}
void compress(vector<long long int>& arr, long long int n) {
  map<long long int, vector<long long int> > pos;
  for (long long int i = 1; i <= n; i++) pos[arr[i]].push_back(i);
  long long int cnt = 1;
  for (auto itr : pos) {
    for (auto elem : itr.second) arr[elem] = cnt;
    cnt++;
  }
}
bool rcomp(long long int a, long long int b) { return a > b; }
void solve() {
  long long int n, d;
  cin >> n >> d;
  vector<long long int> arr(n, 0);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  ;
  vector<vector<long long int> > cycles;
  vector<long long int> visited(n, 0);
  for (long long int i = 0; i < n; i++) {
    if (visited[i]) continue;
    vector<long long int> curr;
    bool istherzero = false;
    long long int ptr = i;
    while (!visited[ptr]) {
      istherzero = istherzero or arr[ptr] == 0;
      visited[ptr] = 1;
      curr.push_back(arr[ptr]);
      ptr -= d;
      ptr = (ptr + n) % n;
    }
    cycles.push_back(curr);
    if (!istherzero) {
      cout << "-1"
           << "\n";
      return;
    }
  }
  long long int ans = 0;
  for (auto myarr : cycles) {
    vector<long long int> temp = myarr;
    for (long long int i = 0; i < myarr.size(); i++) temp.push_back(myarr[i]);
    long long int lst = -1;
    long long int curr = 0;
    for (long long int i = 0; i < temp.size(); i++) {
      if (temp[i] == 0) curr = max(curr, (i - lst - 1)), lst = i;
    }
    ans = max(ans, curr);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  long long int t;
  cin >> t;
  while (t--) solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
