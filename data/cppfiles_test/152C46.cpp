#include <bits/stdc++.h>
using std::make_pair;
using std::pair;
using std::reverse;
using std::set;
using std::sort;
using std::swap;
using std::vector;
const int32_t oo = 1e9;
template <typename T>
T min(std::initializer_list<T> l) {
  const T* it = l.begin();
  const T* end = l.end();
  T answer = *it;
  it++;
  while (it != end) {
    if (*it < answer) answer = *it;
    it++;
  }
  return answer;
}
template <typename T>
T max(std::initializer_list<T> l) {
  const T* it = l.begin();
  const T* end = l.end();
  T answer = *it;
  it++;
  while (it != end) {
    if (*it > answer) answer = *it;
    it++;
  }
  return answer;
}
class all_binaries_iterator {
 private:
  bool end;
  vector<int> v;

 public:
  all_binaries_iterator(int n) {
    end = false;
    v.resize(n, 0);
  }
  bool operator!=(const all_binaries_iterator r) const { return !end; }
  const vector<int>& operator*() const { return v; }
  const all_binaries_iterator& operator++() {
    unsigned int ind = 0;
    while (ind < v.size() && v[ind] == 1) v[ind++] = 0;
    if (ind == v.size())
      end = true;
    else
      v[ind] = 1;
    return *this;
  }
};
class all_binaries {
 private:
  int n;

 public:
  all_binaries(int n) : n(n) {}
  all_binaries_iterator begin() const { return all_binaries_iterator(n); }
  all_binaries_iterator end() const { return all_binaries_iterator(0); }
};
class all_permutations_iterator {
 private:
  vector<int> v;

 public:
  all_permutations_iterator(int n) {
    v.resize(n);
    for (int i = 1; i <= n; i++) v[i - 1] = i;
  }
  bool operator!=(const all_permutations_iterator r) const {
    for (unsigned int i = 0; i < v.size() - 1; i++)
      if (v[i] < v[i + 1]) return true;
    return false;
  }
  const vector<int>& operator*() const { return v; }
  const all_permutations_iterator& operator++() {
    unsigned int indx = v.size() - 2;
    while (v[indx] > v[indx + 1]) indx--;
    unsigned int smallest_larger = indx + 1;
    while (smallest_larger + 1 < v.size() && v[smallest_larger + 1] > v[indx])
      smallest_larger++;
    swap(v[indx], v[smallest_larger]);
    reverse(v.begin() + indx + 1, v.end());
    return *this;
  }
};
class all_permutations {
 private:
  int n;

 public:
  all_permutations(int n) : n(n) {}
  all_permutations_iterator begin() const {
    return all_permutations_iterator(n);
  }
  all_permutations_iterator end() const { return all_permutations_iterator(0); }
};
const int max_size = 1e6;
bool brute_force(int* a, int n) {
  for (auto bin : all_binaries(n)) {
    for (int i = 0; i < n; i++) {
      if ((a[i] < 0 && bin[i] == 0) || (a[i] > 0 && bin[i] == 1)) a[i] = -a[i];
    }
    bool good_solution = true;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] > a[j])
          for (int k = j + 1; k < n; k++)
            if (a[j] > a[k]) good_solution = false;
    if (good_solution) return true;
  }
  return false;
}
int gi(int ind, int n) { return ind + n + 1; }
bool dp_n3(int* a, int n) {
  bool DP[n][2 * n + 2][2 * n + 2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2 * n + 2; j++)
      for (int k = 0; k < 2 * n + 2; k++) DP[i][j][k] = false;
  DP[0][gi(a[0], n)][0] = true;
  DP[0][gi(-a[0], n)][0] = true;
  for (int i = 0; i < n - 1; i++)
    for (int j = -n - 1; j <= n; j++)
      for (int k = -n - 1; k <= n; k++)
        if (DP[i][gi(j, n)][gi(k, n)]) {
          if (a[i + 1] > j) DP[i + 1][gi(a[i + 1], n)][gi(k, n)] = true;
          if (a[i + 1] > k) DP[i + 1][gi(j, n)][gi(a[i + 1], n)] = true;
          if (-a[i + 1] > j) DP[i + 1][gi(-a[i + 1], n)][gi(k, n)] = true;
          if (-a[i + 1] > k) DP[i + 1][gi(j, n)][gi(-a[i + 1], n)] = true;
        }
  for (int j = -n - 1; j <= n; j++)
    for (int k = -n - 1; k <= n; k++)
      if (DP[n - 1][gi(j, n)][gi(k, n)]) return true;
  return false;
}
bool dp_n2(int* a, int n) {
  int DP[n][2 * n + 2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2 * n + 2; j++) DP[i][j] = oo;
  DP[0][gi(a[0], n)] = -oo;
  DP[0][gi(-a[0], n)] = -oo;
  for (int i = 0; i < n - 1; i++)
    for (int j = -n - 1; j <= n; j++)
      if (DP[i][gi(j, n)] != oo) {
        if (a[i + 1] > j)
          DP[i + 1][gi(a[i + 1], n)] =
              min({DP[i + 1][gi(a[i + 1], n)], DP[i][gi(j, n)]});
        else if (a[i + 1] > DP[i][gi(j, n)])
          DP[i + 1][gi(j, n)] = min({DP[i + 1][gi(j, n)], a[i + 1]});
        if (-a[i + 1] > j)
          DP[i + 1][gi(-a[i + 1], n)] =
              min({DP[i + 1][gi(-a[i + 1], n)], DP[i][gi(j, n)]});
        else if (-a[i + 1] > DP[i][gi(j, n)])
          DP[i + 1][gi(j, n)] = min({DP[i + 1][gi(j, n)], -a[i + 1]});
      }
  for (int j = 0; j < 2 * n + 2; j++)
    if (DP[n - 1][j] != oo) return true;
  return false;
}
bool dp_n(int* a, int n) {
  int DP[n][2];
  int prev[n][2];
  DP[0][0] = -oo;
  DP[0][1] = -oo;
  for (int i = 1; i < n; i++) {
    DP[i][0] = DP[i][1] = oo;
    if (-a[i] > DP[i - 1][0])
      if (DP[i][0] > -a[i - 1]) {
        DP[i][0] = -a[i - 1];
        prev[i][0] = 0;
      }
    if (-a[i] > DP[i - 1][1])
      if (DP[i][0] > a[i - 1]) {
        DP[i][0] = a[i - 1];
        prev[i][0] = 1;
      }
    if (-a[i] > -a[i - 1])
      if (DP[i][0] > DP[i - 1][0]) {
        DP[i][0] = DP[i - 1][0];
        prev[i][0] = 0;
      }
    if (-a[i] > a[i - 1])
      if (DP[i][0] > DP[i - 1][1]) {
        DP[i][0] = DP[i - 1][1];
        prev[i][0] = 1;
      }
    if (a[i] > DP[i - 1][0])
      if (DP[i][1] > -a[i - 1]) {
        DP[i][1] = -a[i - 1];
        prev[i][1] = 0;
      }
    if (a[i] > DP[i - 1][1])
      if (DP[i][1] > a[i - 1]) {
        DP[i][1] = a[i - 1];
        prev[i][1] = 1;
      }
    if (a[i] > -a[i - 1])
      if (DP[i][1] > DP[i - 1][0]) {
        DP[i][1] = DP[i - 1][0];
        prev[i][1] = 0;
      }
    if (a[i] > a[i - 1])
      if (DP[i][1] > DP[i - 1][1]) {
        DP[i][1] = DP[i - 1][1];
        prev[i][1] = 1;
      }
  }
  if (DP[n - 1][0] == oo && DP[n - 1][1] == oo) return false;
  int next = prev[n - 1][1];
  if (DP[n - 1][0] != oo) {
    next = prev[n - 1][0];
    a[n - 1] = -a[n - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    if (next == 0) a[i] = -a[i];
    next = prev[i][next];
  }
  return true;
}
int main() {
  int q, n;
  int a[max_size];
  [&] { return scanf("%d", &q); }();
  ;
  while (q--) {
    [&] { return scanf("%d", &n); }();
    ;
    for (int i = 0; i < n; i++) [&] { return scanf("%d", &a[i]); }();
    ;
    bool result = dp_n(a, n);
    if (result) {
      printf("YES\n");
      for (int i = 0; i < n; i++) printf("%d ", a[i]);
      printf("\n");
    } else
      printf("NO\n");
  }
  return 0;
}
