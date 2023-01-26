#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first == p2.first) {
    return p1.second > p2.second;
  }
  return p1.first < p2.first;
}
void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
}
bool isprime(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void printv(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
void printvl(vector<long long> arr, long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
void printa(int *arr, int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
void printal(long long *arr, long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
void yes() {
  cout << "Yes" << endl;
  return;
}
void no() {
  cout << "No" << endl;
  return;
}
bool check_palind(string s) {
  long long i = 0;
  long long j = s.length() - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
void solution() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  long long a[n + 1];
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i] == '+')
        a[i + 1] = 1;
      else
        a[i + 1] = -1;
    } else {
      if (s[i] == '+')
        a[i + 1] = -1;
      else
        a[i + 1] = 1;
    }
  }
  a[0] = 0;
  for (long long i = 1; i < n + 1; i++) {
    long long temp = a[i - 1] + a[i];
    a[i] = temp;
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    long long x = a[l - 1];
    long long y = a[r];
    long long z = abs(y - x);
    if (z == 0)
      cout << 0 << endl;
    else if (z % 2 == 0)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long ts = 1;
  cin >> ts;
  while (ts--) {
    solution();
  }
}
