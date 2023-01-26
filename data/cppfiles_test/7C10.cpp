#include <bits/stdc++.h>
using namespace std;
template <typename T, int NDIMS>
struct tensor_view {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

 protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  T* data;
  tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_,
              T* data_)
      : shape(shape_), strides(strides_), data(data_) {}

 public:
  tensor_view() : shape{0}, strides{0}, data(nullptr) {}

 protected:
  int flatten_index(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      res += idx[i] * strides[i];
    }
    return res;
  }
  int flatten_index_checked(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      assert(0 <= idx[i] && idx[i] < shape[i]);
      res += idx[i] * strides[i];
    }
    return res;
  }

 public:
  T& operator[](std::array<int, NDIMS> idx) const {
    return data[flatten_index(idx)];
  }
  T& at(std::array<int, NDIMS> idx) const {
    return data[flatten_index_checked(idx)];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
      int idx) const {
    std::array<int, NDIMS - 1> nshape;
    std::copy(shape.begin() + 1, shape.end(), nshape.begin());
    std::array<int, NDIMS - 1> nstrides;
    std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
    T* ndata = data + (strides[0] * idx);
    return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(
      int idx) const {
    assert(0 <= idx && idx < shape[0]);
    return operator[](idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() const {
    return *data;
  }
  template <typename U, int D>
  friend struct tensor_view;
  template <typename U, int D>
  friend struct tensor;
};
template <typename T, int NDIMS>
struct tensor {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

 protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  int len;
  T* data;

 public:
  tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}
  explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
    shape = shape_;
    strides[NDIMS - 1] = 1;
    for (int i = NDIMS - 1; i > 0; i--) {
      strides[i - 1] = strides[i] * shape[i];
    }
    len = strides[0] * shape[0];
    data = new T[len];
    std::fill(data, data + len, t);
  }
  tensor(const tensor& o)
      : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
    for (int i = 0; i < len; i++) {
      data[i] = o.data[i];
    }
  }
  tensor& operator=(tensor&& o) noexcept {
    using std::swap;
    swap(shape, o.shape);
    swap(strides, o.strides);
    swap(len, o.len);
    swap(data, o.data);
    return *this;
  }
  tensor(tensor&& o) : tensor() { *this = std::move(o); }
  tensor& operator=(const tensor& o) { return *this = tensor(o); }
  ~tensor() { delete[] data; }
  using view_t = tensor_view<T, NDIMS>;
  view_t view() { return tensor_view<T, NDIMS>(shape, strides, data); }
  operator view_t() { return view(); }
  using const_view_t = tensor_view<const T, NDIMS>;
  const_view_t view() const {
    return tensor_view<const T, NDIMS>(shape, strides, data);
  }
  operator const_view_t() const { return view(); }
  T& operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
  T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
  const T& operator[](std::array<int, NDIMS> idx) const { return view()[idx]; }
  const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
      int idx) {
    return view()[idx];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(
      int idx) {
    return view().at(idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type
  operator[](int idx) const {
    return view()[idx];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type at(
      int idx) const {
    return view().at(idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() {
    return *view();
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), const T&>::type operator*() const {
    return *view();
  }
};
vector<int> prefix_func(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> kmp(const string& s, const string& pat) {
  vector<int> p = prefix_func(pat + '\0' + s), res;
  for (int i = (int)p.size() - (int)s.size(); i < p.size(); i++)
    if (p[i] == pat.size()) res.push_back(i - 2 * pat.size());
  return res;
}
void compute_automaton(string s, vector<vector<int>>& aut) {
  s += '#';
  int n = s.size();
  vector<int> pi = prefix_func(s);
  aut.assign(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 2; c++) {
      if (i > 0 && '0' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('0' + c == s[i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<vector<int>> aut;
  compute_automaton(b, aut);
  const int INF = 1e9;
  tensor<int, 2> dp({m + 1, n - m + 2}, INF);
  dp[{0, 0}] = 0;
  for (int i = 0; i < n; i++) {
    tensor<int, 2> ndp({m + 1, n - m + 2}, INF);
    for (int pi = 0; pi <= m; pi++) {
      for (int c = 0; c <= 1; c++) {
        int add = (a[i] != ('0' + c));
        int npi = aut[pi][c];
        for (int k = 0; k < n - m + 2; k++) {
          if (npi == m) {
            if (k != 0)
              ndp[{npi, k}] = min(ndp[{npi, k}], dp[{pi, k - 1}] + add);
          } else {
            ndp[{npi, k}] = min(ndp[{npi, k}], dp[{pi, k}] + add);
          }
        }
      }
    }
    swap(dp, ndp);
  }
  for (int k = 0; k <= n - m + 1; k++) {
    int ans = INF;
    for (int pi = 0; pi <= m; pi++) ans = min(ans, dp[{pi, k}]);
    if (ans == INF)
      cout << -1 << " ";
    else
      cout << ans << " ";
  }
}
