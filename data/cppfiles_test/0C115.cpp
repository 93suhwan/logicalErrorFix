#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;
struct phantu {
  int l;
  int r;
  int d;
};
long long gcd(long long a, long long b) {
  long long tmp;
  while (b != 0) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int gcd(int a, int b) {
  int tmp;
  while (b != 0) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int isprime(int n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 1;
  return 0;
}
int find(vector<pair<int, int>> arr, int l, int r, int x) {
  if (l > r) return -1;
  if (arr[l].first >= x) return arr[l].second;
  if (arr[r].first >= x) return arr[r].second;
  int a = (l + r) / 2;
  if (arr[a].first >= x)
    return arr[a].second;
  else if (arr[a].first < x)
    return find(arr, a + 1, r, x);
  else
    return find(arr, l, a - 1, x);
}
int check(string s, int i, int j) {
  int cnt = 0, cnt1 = 0;
  for (int k = i; k <= j; k++)
    if (s[i] == 'a')
      cnt++;
    else
      cnt1++;
  if (cnt == cnt1) return 1;
  return 0;
}
int mu(int n, int j) {
  int k = 1;
  for (int i = 0; i < j; i++) k *= 10;
  return k;
}
int check(int a, int n) {
  string s = to_string(a), ch = to_string(n);
  int cnt = 0, i = 0, j = 0;
  while (i < s.length() && j < ch.length()) {
    if (ch[j] == s[i]) {
      i++;
      cnt++;
    }
    j++;
  }
  return s.length() + ch.length() - 2 * cnt;
}
bool cmp(pair<string, int> a, pair<string, int> b) { return 1; }
long long count(long long a, long long x) {
  long long cnt = 0;
  while (a % x == 0) {
    cnt++;
    a /= x;
  }
  return cnt;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
    for (int j = 0; j < m; j++)
      if (j % 2 != 0) arr[i].first[j] = 'Z' - (arr[i].first[j] - 'A');
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) cout << arr[i].second << " ";
  cout << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
