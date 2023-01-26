#include <bits/stdc++.h>
using namespace std;
void precision(int a) { cout << setprecision(a) << fixed; }
vector<string> compositeDp = {
    "1",   "4",   "6",   "8",    "9",    "22",   "33",  "55",  "77",
    "25",  "27",  "35",  "57",   "75",   "235",  "237", "357", "573",
    "537", "735", "753", "2375", "2537", "2573", "2735"};
vector<long long> factors(long long n) {
  vector<long long> first;
  long long tem = 1;
  for (long long x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      first.push_back(x);
      n /= x;
    }
  }
  if (n > 1) first.push_back(n);
  return first;
}
bool marked[200000 + 100];
bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}
void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) {
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
}
long long stringToint(string str) {
  int num = stoi(str);
  return num;
}
int bin_search(int arr[], int target, int n) {
  int l = 0, r = n - 1, mid = 0;
  while (l <= r) {
    mid = l + ((r - l) / 2);
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
vector<int> computeLPSArray(string str) {
  int n = str.size(), i = 0, j = 1;
  vector<int> a(n, 0);
  while (j < n) {
    if (str[i] != str[j]) {
      while (str[i] != str[j] && i > 0) i = a[i - 1];
      if (str[i] == str[j])
        a[j++] = ++i;
      else
        a[j++] = 0;
    } else
      a[j++] = ++i;
  }
  return a;
}
int hamming(int a, int b) { return __builtin_popcount(a ^ b); }
bool cmp(int a, int b) { return a > b; }
void reset() {
  for (int i = 0; i < 200000 + 100; i++) {
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, ans, sum = 0;
    cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;
    sort((arr).begin(), (arr).end());
    sum = -arr[0];
    ans = arr[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, arr[i] + sum);
      if (ans < 0)
        sum += ans;
      else
        sum -= ans;
    }
    cout << ans << "\n";
  }
  return 0;
}
