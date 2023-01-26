#include <bits/stdc++.h>
using namespace std;
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int modInverse(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    long long int res = (x % m + m) % m;
    return res;
  }
}
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
bool status[400000];
int dif[100000] = {0};
void siv(int N) {
  int sq = sqrt(N);
  for (int i = 4; i <= N; i += 2) {
    status[i] = 1;
  }
  for (int i = 3; i <= sq; i += 2) {
    if (status[i] == 0) {
      for (int j = i * i; j <= N; j += i) status[j] = 1;
    }
  }
  status[1] = 1;
}
void setDif() {
  int j = 0;
  for (int i = 2; i < 400000; i++) {
    if (status[i] == 0) {
      dif[j] = (i);
      j++;
    }
  }
}
struct cmpStruct {
  bool operator()(pair<int, int> const &lhs, pair<int, int> const &rhs) const {
    if (lhs.first != rhs.first)
      return lhs.first < rhs.first;
    else {
      return lhs.second < rhs.second;
    }
  }
};
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool desc(const int &a, const int &b) { return a > b; }
void NO() {
  cout << "NO"
       << "\n";
}
void YES() {
  cout << "YES"
       << "\n";
}
void No() {
  cout << "No"
       << "\n";
}
void Yes() {
  cout << "Yes"
       << "\n";
}
priority_queue<pair<int, int>> pq;
int main() {
  fastIO();
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = n / 3;
    int dif = n % 3;
    if (dif == 1) {
      cout << x + 1 << " " << x << endl;
    } else if (dif == 2) {
      cout << x << " " << x + 1 << endl;
    } else {
      cout << x << " " << x << endl;
    }
  }
  return 0;
}
