#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _display(vector<T> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
long long _binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int _gcd(long long int a, long long int b) {
  return b == 0 ? a : _gcd(b, a % b);
}
int _issorted(vector<long long int> A) {
  for (int i = 0; i < A.size() - 1; i++) {
    if (A[i] > A[i + 1]) return 0;
  }
  return 1;
}
bool _isprime(long long int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= (n); i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long int highestPowerof2(long long int n) {
  long long int p = (long long int)log2(n);
  return (long long int)pow(2, p);
}
long long int countDivisors(long long int n) {
  long long int cnt = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
long long int countSquares(long long int a, long long int b) {
  return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}
long long int countCubes(long long int a, long long int b) {
  return (floor(cbrt(b)) - ceil(cbrt(a)) + 1);
}
long long int SquareCube(long long int N) {
  long long int cnt = 0, i = 1;
  while (long long int(pow(i, 6)) <= N) {
    ++cnt;
    ++i;
  }
  return cnt;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int countOdd(int L, int R) {
  int N = (R - L) / 2;
  if (R % 2 != 0 || L % 2 != 0) N += 1;
  return N;
}
int main() {
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    map<pair<long long int, long long int>, long long int> mp;
    vector<pair<long long int, long long int>> A;
    vector<pair<long long int, pair<long long int, long long int>>> A1;
    for (long long int i = 0; i < n; i++) {
      long long int x, y;
      cin >> x >> y;
      A1.push_back({abs(x - y), {x, y}});
      mp[{x, y}]++;
    }
    sort(A1.begin(), A1.end());
    for (int i = 0; i < A1.size(); i++) {
      A.push_back(A1[i].second);
    }
    vector<pair<pair<long long int, long long int>, long long int>> Ans;
    map<long long int, long long int> mp1;
    for (int i = 0; i < A.size(); i++) {
      long long int l = A[i].first;
      long long int r = A[i].second;
      if (l == r) {
        Ans.push_back({{l, r}, l});
        mp1[l]++;
        continue;
      }
      for (int j = l; j <= r; j++) {
        int x1 = j - 1;
        int y1 = j + 1;
        pair<long long int, long long int> p1 = {l, x1};
        pair<long long int, long long int> p2 = {y1, r};
        if (mp1[j] == 0 && (mp[p1] != 0 || mp[p2] != 0)) {
          Ans.push_back({{l, r}, j});
          mp1[j]++;
          break;
        }
      }
    }
    for (int i = 0; i < Ans.size(); i++) {
      cout << Ans[i].first.first << " " << Ans[i].first.second << " "
           << Ans[i].second;
      cout << endl;
    }
  }
}
