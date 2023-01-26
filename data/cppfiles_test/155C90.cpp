#include <bits/stdc++.h>
using namespace std;
int mpow(long long first, long long second);
bool isPalindrone(string s);
void in_arr(int arr[], int n);
void findPrime();
long long _mod(long long a);
int prime[1];
void solve() {
  int n;
  cin >> n;
  int arr[n];
  in_arr(arr, n);
  string s;
  cin >> s;
  vector<int> v1, v2;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      v2.push_back(i);
    } else {
      v1.push_back(i);
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int j = v2.size();
  int temp = j;
  j++;
  int l = j - 1;
  int ans[n];
  memset(ans, -1, sizeof(ans));
  int o[n + 1];
  memset(o, -1, sizeof(o));
  for (auto first : v1) {
    if (arr[first] > temp && o[arr[first]] == -1) {
      ans[first] = arr[first];
      o[arr[first]] = 1;
    }
  }
  for (auto first : v2) {
    if (arr[first] <= temp && o[arr[first]] == -1) {
      ans[first] = arr[first];
      o[arr[first]] = 1;
    }
  }
  for (auto first : v1) {
    while (o[j] == 1) j++;
    if (ans[first] == -1) {
      ans[first] = j;
      j++;
    }
  }
  j = 1;
  for (auto first : v2) {
    while (o[j] == 1) j++;
    if (ans[first] == -1) {
      ans[first] = j;
      j++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
int mpow(long long first, long long second) {
  long long res = 1;
  while (second > 0) {
    if (second % 2 == 1) {
      res = (res * first) % 1000000007;
    }
    second = second / 2;
    first = (first * first) % 1000000007;
  }
  return (int)res;
}
void in_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
void findPrime() {
  int n = 1000001;
  prime[1] = -1;
  for (int i = 2; i < n; i++) {
    if (prime[i] != 0) {
      continue;
    }
    for (int j = i + i; j < n; j += i) {
      prime[j] = -1;
    }
  }
}
bool isPalindrone(string s) {
  int j = s.length() - 1;
  int i = 0;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
long long _mod(long long a) {
  return (1000000007 + a % 1000000007) % 1000000007;
}
