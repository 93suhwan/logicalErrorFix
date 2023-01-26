#include <bits/stdc++.h>
using namespace std;
int getIndexEl(string s, int j, char el) {
  int index = -1;
  bool f = false;
  for (int i = j; i < s.size() && !f; i++) {
    if (s[i] == el) {
      f = true;
      index = i;
    }
  }
  return index;
}
void readVector(vector<long long> &vec, size_t n) {
  for (size_t i = 0; i < n; i++) {
    cin >> vec[i];
  }
}
void writeVector(vector<long long> vec, size_t n) {
  for (size_t i = 0; i < n; i++) {
    cout << vec[i] << ' ';
  }
  cout << endl;
}
long long check(long long n, long long num) {
  string str_n = to_string(n);
  string str_num = to_string(num);
  long long cnt = 0;
  long long i_n = 0, i_num = 0;
  for (; str_n[i_n] != '\0' && str_num[i_num] != '\0'; i_n++) {
    if (str_num[i_num] == str_n[i_n]) {
      i_num++;
    } else {
      cnt++;
    }
  }
  return str_n.size() - i_n + str_num.size() - i_num + cnt;
}
void f(vector<long long> &a, const size_t i) {
  if (a[i] > a[i + 1]) {
    {
      long long tmp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = tmp;
    };
  }
}
bool check_sort_vec(vector<long long> vec) {
  bool f = true;
  for (long long i = 0; i + 1 < vec.size() && f; i++) {
    f = vec[i] <= vec[i + 1];
  }
  return f;
}
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    readVector(a, n);
    long long i = 0;
    while (!check_sort_vec(a)) {
      if (++i % 2 == 1) {
        for (long long j = 0; j + 2 <= n; j += 2) {
          f(a, j);
        }
      } else {
        for (long long j = 1; j + 2 <= n; j += 2) {
          f(a, j);
        }
      }
    }
    cout << i << endl;
  }
  return 0;
}
