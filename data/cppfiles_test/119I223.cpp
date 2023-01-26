#include <bits/stdc++.h>
using namespace std;
long long arr1[1000001];
template <typename T>
T myMax(T x, T y) {
  return (x > y) ? x : y;
}
template <typename T>
T myMin(T x, T y) {
  return (x < y) ? x : y;
}
template <typename T>
T sum(T x, T y) {
  return (x + y);
}
template <typename T>
T Mean(T x, T y) {
  return (x + ((y - x) / 2));
}
void seive() {
  for (long long i = 0; i <= 1000000; i++) {
    arr1[i] = 1;
  }
  for (long long i = 2; i * i <= 1000000; i++) {
    if (arr1[i] == 1) {
      arr1[i] = 1;
      for (long long j = i * i; j <= 1000000; j = j + i) {
        arr1[j] = 0;
      }
    }
  }
}
long long find_occurances(string s) {
  string s1 = "";
  long long c = 0;
  for (long long i = 0; i < 3; i++) {
    s1 = s1 + s[i];
  }
  if (s1 == "abc") {
    c++;
  }
  long long n = s.size();
  long long l = 0;
  long long r = 2;
  while (r < n - 1) {
    s1.erase(s1.begin());
    l++;
    r++;
    s1 += s[r];
    if (s1 == "abc") {
      c++;
    }
  }
  return c;
}
bool check_power_of_2(long long x) {
  if ((x & (x - 1)) == 0) {
    return true;
  }
  return false;
}
bool cmp(pair<long long, pair<long long, long long>> x,
         pair<long long, pair<long long, long long>> y) {
  if (x.first == y.first) {
    return x.second.second < y.second.second;
  }
  return x.first < y.first;
}
bool cmp1(pair<long long, long long> p, pair<long long, long long> q) {
  return p.first < q.second;
}
bool check(vector<long long>& v) {
  if (v[0] == 1) {
    bool flag1 = true;
    for (long long i = 1; i < v.size(); i++) {
      if (v[i] != v[i - 1]) {
        flag1 = false;
        break;
      }
    }
    return flag1;
  } else {
    return false;
  }
}
bool check_prime(long long x) {
  if (x == 2) {
    return true;
  }
  if (x == 3) {
    return true;
  }
  if ((x % 2) == 0) {
    return false;
  }
  if ((x % 3) == 0) {
    return false;
  }
  for (long long i = 5; i * i <= x; i = i + 6) {
    if ((x % i) == 0) {
      return false;
    }
    if ((x % (i + 2)) == 0) {
      return false;
    }
  }
  return true;
}
bool check_array(vector<long long>& v) {
  for (long long i = 1; i < v.size(); i++) {
    if (v[i] == v[i - 1]) return false;
  }
  return true;
}
bool is_vowel(char x) {
  if ((x == 'a') || (x == 'e') || (x == 'o') || (x == 'i') || (x == 'u')) {
    return true;
  }
  return false;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long l = 0;
    long long r = n - 1;
    while (l < r) {
      if ((arr[r] - arr[l]) > 1) {
        long long x = arr[r] - arr[l];
        arr[l] = arr[l] + x / 2;
        arr[r] = arr[r] - x / 2;
      }
      l++;
      r--;
    }
    sort(arr, arr + n);
    cout << arr[n - 1] - arr[0] << "\n";
  }
  return 0;
}
