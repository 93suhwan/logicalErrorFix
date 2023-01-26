#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = std::pair<int, int>;
template <typename T>
static inline T gcd(T a, T b) {
  a = std::abs(a);
  b = std::abs(b);
  while (b > 0) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
template <typename T>
static inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
static inline T sqr(T a) {
  return a * a;
}
template <typename T>
static inline bool remin(T &a, const T &val) {
  if (a > val) {
    a = val;
    return true;
  }
  return false;
}
template <typename T>
static inline bool remax(T &a, const T &val) {
  if (a < val) {
    a = val;
    return true;
  }
  return false;
}
static inline ll nxt() {
  int64_t first;
  scanf("%" PRId64, &first);
  return first;
}
static inline void skipEndLine() {
  char c = getchar();
  while (c != '\n') {
    c = getchar();
  }
}
static inline std::string nxtLine() {
  std::string ret;
  char c = '\n';
  while (true) {
    c = getchar();
    if (c == '\n' || c == '\r' || c == -1) {
      break;
    }
    ret.push_back(c);
  }
  return ret;
}
static inline std::string nxtString() {
  std::string ret;
  char c = '\n';
  while (true) {
    c = getchar();
    if (!isspace(c)) {
      break;
    }
  }
  if (c == -1) {
    return ret;
  }
  ret.push_back(c);
  while (true) {
    c = getchar();
    if (isspace(c) || c == -1) {
      break;
    }
    ret.push_back(c);
  }
  return ret;
}
static std::chrono::system_clock::time_point clock_t0;
static inline void init_time() { clock_t0 = std::chrono::system_clock::now(); }
static inline double get_time() {
  auto t = std::chrono::system_clock::now();
  return std::chrono::duration<double>((t - clock_t0)).count();
}
static inline void print_time(const std::string &name) {
  std::cerr << name << " " << get_time() << "s." << std::endl;
}
template <class T>
static inline T pw(T a, ll n) {
  T ret = T(1);
  while (n > 0) {
    if (n & 1) ret = ret * a;
    a = a * a;
    n >>= 1;
  }
  return ret;
}
static inline ll pw(ll a, ll n, ll m) {
  a %= m;
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return ret;
}
class ThreadPool {
 public:
  ThreadPool(size_t);
  template <class F, class... Args>
  auto enqueue(F &&f, Args &&...args)
      -> std::future<typename std::result_of<F(Args...)>::type>;
  ~ThreadPool();

 private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()> > tasks;
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};
inline ThreadPool::ThreadPool(size_t threads) : stop(false) {
  for (size_t i = 0; i < threads; ++i) {
    auto f = [this] {
      for (;;) {
        std::function<void()> task;
        {
          std::unique_lock<std::mutex> lock(this->queue_mutex);
          this->condition.wait(
              lock, [this] { return this->stop || !this->tasks.empty(); });
          if (this->stop && this->tasks.empty()) return;
          task = std::move(this->tasks.front());
          this->tasks.pop();
        }
        task();
      }
    };
    workers.emplace_back(f);
  }
}
template <class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&...args)
    -> std::future<typename std::result_of<F(Args...)>::type> {
  using return_type = typename std::result_of<F(Args...)>::type;
  auto task = std::make_shared<std::packaged_task<return_type()> >(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...));
  std::future<return_type> res = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    if (stop) {
      throw std::runtime_error("enqueue on stopped ThreadPool");
    }
    tasks.emplace([task]() { (*task)(); });
  }
  condition.notify_one();
  return res;
}
inline ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    stop = true;
  }
  condition.notify_all();
  for (std::thread &worker : workers) {
    worker.join();
  }
}
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 * 31 + h2;
  }
};
static const ld PI = acosl(-1.0);
static std::mt19937_64 generator{123123123};
using namespace std;
void prepare() {}
void solve(int test) {
  int n = nxt();
  string s = nxtString();
  string t = s;
  sort((t).begin(), (t).end());
  int k = 0;
  for (int(i) = 0; (i) < int(s.length()); ++(i)) {
    k += s[i] != t[i];
  }
  cout << k << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init_time();
  prepare();
  int t = 1;
  t = nxt();
  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  print_time("Time:");
  return 0;
}
