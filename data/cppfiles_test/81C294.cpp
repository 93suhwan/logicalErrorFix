#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
template <class T>
void swp(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modex(long long x, unsigned int y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
const long long MOD = 998244353;
const long long mod = 1e9 + 7;
string solve(string a, int k, vector<int> &v, int &cur) {
  if (((long long)(a).size()) == 1) {
    v[a[0] - '0']++;
    cur = 1;
    return a;
  }
  string ans(1, a[0]);
  v[a[0] - '0']++;
  cur = 1;
  for (int i = 1; i < ((long long)(a).size()); ++i) {
    if (v[a[i] - '0']) {
      ans += a[i];
    } else {
      if (cur < k) {
        v[a[i] - '0']++;
        ans += a[i];
        cur++;
      } else {
        bool b = false;
        for (int j = (a[i] - '0'); j < 10; ++j) {
          if (v[j]) {
            ans += to_string(j);
            b = true;
            break;
          }
        }
        if (b) {
          for (int j = 0; j < 10; ++j) {
            if (v[j]) {
              while (((long long)(ans).size()) != ((long long)(a).size())) {
                ;
                ans += to_string(j);
              }
              break;
            }
          }
          return ans;
        } else if (!b) {
          vector<int> v1(10, 0);
          cur = 1;
          string x = solve(to_string(stoi(ans) + 1), k, v1, cur);
          if (cur == k) {
            for (int j = 0; j < 10; ++j) {
              if (v1[j] == 1) {
                while (((long long)(x).size()) != ((long long)(a).size()))
                  x += to_string(j);
                break;
              }
            }
          } else {
            while (((long long)(x).size()) != ((long long)(a).size())) {
              x += to_string(0);
            }
            if (v1[0] != 0) {
              cur++;
              v1[0] = 1;
            }
          }
          v = v1;
          return x;
        }
      }
    }
  }
  return ans;
}
bool fun(string s, string b) {
  if (s.find(b[0]) != -1) {
    long long x = s.find(b[0]);
    if (s.find(b[1], x + 1) != -1) return true;
  }
  return false;
}
int main() {
  long long t;
  cin >> t;
  for (int it = 0; it < t; ++it) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long> v(n);
    if (s[0] == '+') {
      v[0] = 1;
    } else {
      v[0] = -1;
    }
    for (long long i = 1; i < n; i++) {
      long long z = -1;
      if (s[i] == '+') z = 1;
      if (i % 2) {
        v[i] = v[i - 1] - z;
      } else {
        v[i] = v[i - 1] + z;
      }
    }
    for (long long i = 0; i < q; i++) {
      long long l, r;
      cin >> l >> r;
      if ((r - l + 1) % 2)
        cout << 1 << "\n";
      else {
        long long x = 0;
        if (l == 1) {
          x = v[r - 1];
        } else {
          x = v[r - 1] - v[l - 2];
        }
        if (x) {
          cout << 2 << "\n";
        } else {
          cout << 0 << "\n";
        }
      }
    }
  }
  return 0;
}
