#include <bits/stdc++.h>
using std::make_pair;
using std::pair;
using std::reverse;
using std::set;
using std::sort;
using std::swap;
using std::vector;
const int32_t oo = 1e9;
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
    for (int i = 0; i < v.size() - 1; i++)
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
bool greed(int* a, int n) {
  int top = -a[0];
  int bot = -oo;
  for (int i = 1; i < n; i++) {
    if (bot > -a[i]) {
      if (bot > a[i]) return false;
      if (a[i] > top)
        top = a[i];
      else
        bot = a[i];
    } else {
      if (-a[i] > top)
        top = -a[i];
      else
        bot = -a[i];
    }
  }
  return true;
}
bool kinda_brute(int* a, int n) {
  set<pair<int, int>> prev;
  set<pair<int, int>> curr;
  prev.insert(make_pair(-a[0], -oo));
  for (int i = 1; i < n; i++) {
    curr.clear();
    for (auto el : prev) {
      if (a[i] > el.first)
        curr.insert(make_pair(a[i], el.second));
      else if (a[i] > el.second)
        curr.insert(make_pair(el.first, a[i]));
      if (-a[i] > el.first)
        curr.insert(make_pair(-a[i], el.second));
      else if (-a[i] > el.second)
        curr.insert(make_pair(el.first, -a[i]));
    }
    swap(prev, curr);
  }
  return prev.size() > 0;
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
    printf(greed(a, n) ? "YES\n" : "NO\n");
  }
  return 0;
}
