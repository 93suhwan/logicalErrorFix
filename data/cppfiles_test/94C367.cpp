#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int mod(long long int a, long long int b) { return ((a % b) + b) % b; }
long long int MODnumber(long long int a) {
  return (a % 998244353 + 998244353) % 998244353;
}
long long int MODsum(long long int a, long long int b) {
  return ((a % 998244353 + b % 998244353) % 998244353 + 998244353) % 998244353;
}
long long int MODproduct(long long int a, long long int b) {
  return (((a % 998244353) * (b % 998244353)) % 998244353 + 998244353) %
         998244353;
}
void solve() {
  string str;
  cin >> str;
  if (str.size() == 1) {
    cout << stoi(str) - 1 << "\n";
    return;
  }
  long long int ans1 = 0;
  long long int ans2 = 0;
  string str2, str1;
  for (int i = 0; i < str.size(); i++) {
    if (i % 2 == 0) str2 += str[i];
    if (i % 2 != 0) str1 += str[i];
  }
  long long int cnt1 = stoi(str2);
  cnt1++;
  long long int cnt2 = stoi(str1);
  cnt2++;
  cout << (cnt1 * cnt2) - 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int testCase;
  cin >> testCase;
  while (testCase--) {
    solve();
  }
}
