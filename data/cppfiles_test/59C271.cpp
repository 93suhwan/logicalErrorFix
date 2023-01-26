#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
bool sortbyseca(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortbysecd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
bool sortbysecx(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortbysecastring(const pair<string, int> &a, const pair<string, int> &b) {
  return (a.second < b.second);
}
bool cmp(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  if (a.first != b.first)
    return (a.first < b.first);
  else
    return (a.second < b.second);
}
bool cmp2(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second <= b.second);
}
std::vector<int> numbers;
void seive(long long n) {
  for (long long i = 0; i < n + 2; i++) numbers.push_back(-1);
  numbers[1] = numbers[0] = 0;
  for (long long i = 2; i <= n + 1; i++) {
    if (numbers[i] == -1) {
      for (long long j = i; j <= n + 1; j += i) {
        numbers[j] = i;
      }
    }
  }
}
const int MOD = 1e9 + 7;
long long power(long long n, long long i) {
  long long ans = 1;
  while (i > 0) {
    ans *= n;
    ans = ans % MOD;
    i--;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n][5];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < 5; j++) cin >> arr[i][j];
  long long count1 = 0, count2 = 0, count3 = 0;
  for (long long i = 0; i < 5; i++) {
    for (long long j = i + 1; j < 5; j++) {
      count1 = 0, count2 = 0, count3 = 0;
      for (long long k = 0; k < n; k++) {
        if (arr[k][i] == 1 && arr[k][j] == 1)
          count3++;
        else if (arr[k][i] == 1)
          count1++;
        else if (arr[k][j] == 1)
          count2++;
      }
      if (count1 == n / 2 && count2 == n / 2) {
        cout << "YES\n";
        return;
      }
      long long temp = n / 2 - count1, temp2 = n / 2 - count2;
      if (temp >= 0 && temp2 >= 0) {
        if (temp + temp2 == count3) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
