#define DEBUG 0
#define TESTSETS 1

#if DEBUG
#include <ultimate_power_2.h>
#else 
#include <bits/stdc++.h>
#define echo(...) {}
#endif
/* -------------------------------------------------------- Utils ---------------------------------------------------------------- */
#define debug if(DEBUG)
#define pow2(x) (1LL<<(x))
#define st first
#define nd second
#define mt make_tuple
#define gottagofast() std::ios::sync_with_stdio(0); cin.tie(0);
#define band(x, y) ((x) & (y))
#define bor(x, y) ((x) | (y))
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define ffor(i, a, b) for(int i = (a), i##e = (b); i <= i##e; i++)
#define dfor(i, a, b) for(int i = (a), i##e = (b); i >= i##e; i--)

#define forx(i, a, b) for(int i = (a), i##e = (b); i < i##e; i++) //!!! eXclusive
#define dforx(i, a, b) for(int i = (a), i##e = (b); i > i##e; i--)//!!! eXclusive

using std::vector, std::pair, std::string, std::set, std::unordered_map, std::unordered_set, std::multiset, std::unordered_multiset, std::istream, std::min, std::max, std::cin, std::cout, std::map;
using LL = long long;
using ULL = unsigned long long;
constexpr LL Inf = LLONG_MAX / 2 - 1;
constexpr int iInf = INT_MAX / 2 - 1;
LL MOD = 1000 * 1000 * 1000 + 7;
int clamp(int x, int a, int b) { assert(a <= b); return min(max(x, a), b); }
template<class T> LL sum(const vector<T>& vector) { return accumulate(vector.begin(), vector.end(), 0LL); }
template<class T> T max(const vector<T>& vector) { return *max_element(vector.begin(), vector.end()); }
template<class T> T min(const vector<T>& vector) { return *min_element(vector.begin(), vector.end()); }
template<class T> int popcnt(T x) { int c = 0; while (x > 0) c += x & 1, x >>= 1; return c; }
template<class T, class U> pair<T, U> operator+(const pair<T, U>& a, const pair<T, U>& b) { return { a.st + b.st, a.nd + b.nd }; }
template<class T, class U> pair<T, U> operator+=(pair<T, U>& a, const pair<T, U>& b) { return a = a + b; }
template<class T, class U>
istream& operator>>(istream& stream, pair<T, U>& p) { return stream >> p.first >> p.second; }
template<class T>
vector<T> read_vector(int size)
{
    vector<T> res(size);
    for (auto& x : res) cin >> x;
    return res;
}
template<class T>
vector<T> read_vector(int size, const T& delta)
{
    vector<T> res(size);
    for (auto& x : res) cin >> x, x += delta;
    return res;
}
template<class T>
void print_vector(const vector<T>& v)
{
    for (auto& vi : v) cout << vi << " ";
    cout << "\n";
}
vector<LL> factorize(LL x)
{
    assert(x > 0);
    vector<LL> f;
    while (x % 2 == 0)
        f.push_back(2),
        x /= 2;
    for (LL d = 3; d * d <= x; d += 2)
        while (x % d == 0)
            f.push_back(d),
            x /= d;
    if (x > 1)
        f.push_back(x);
    return f;
}
vector<pair<LL, int>> compress(vector<LL> v)
{
    vector<pair<LL, int>> p;
    sort(all(v));
    for (int i = 0, j; i < len(v); i = j) {
        for (j = i + 1; j < len(v) && v[i] == v[j]; j++);
        p.emplace_back(v[i], j - i);
    }
    return p;
}
int randx(int a, int b) { return rand() % (b - a) + a; }//rand exclusive [a, b)
LL fpow(LL a, LL b)
{
    if (b == 0) return 1;
    if (b % 2 == 1) return fpow(a, b - 1) * a % MOD;
    LL p = fpow(a, b / 2);
    return p * p % MOD;
}
LL iceil(LL a, LL b)
{
    assert(a > 0);
    return (a - 1) / b + 1;
}

template<class It, class T>
int scale(It beg, It end, T start)
{
    map<T, T> m{ beg, end };
    for (auto& [x, y] : m)
        y = start++;
    while (beg != end)
        *beg++ = m[*beg];
    return len(m);
}
template<class T>
void sort_and_unique(vector<T>& t)
{
    sort(all(t));
    t.resize(unique(all(t)) - t.begin());
}
int modulo(int a, int b) {
    int res = a % b;
    if (res < 0) res += b;
    return res;
}
template<class T>
void answer(const T& x) {
    cout << x << "\n";
}
vector<int> divisors(int n) {
    vector<int> s;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            s.push_back(n / i),
            s.push_back(i);
    sort_and_unique(s);
    return s;
}
template<class T>
struct fixed_vector
{
    //Array on range [a, b)
    vector<T> mapped; int offset;
    fixed_vector() = default;
    fixed_vector(int a, int b) : mapped(b - a), offset(-a)
    {
    }
    T& operator[](int idx) {
        if (has(idx))
            return mapped[idx + offset];
        exit(69);
        return mapped[0];
    }
    bool has(int idx) {
        return 0 <= idx + offset && idx + offset < len(mapped);
    }
};

/* ------------------------------------------------------------------------------------------------------------------------------ */

int n, m;
vector<vector<int>> a;

void Input()
{
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    forx(i, 0, n) 
        forx(j, 0, m)
            cin >> a[i][j];
}

void Solve()
{
    forx(i, 0, n)
        a[i].push_back(i);//og idx backup
    sort(all(a), [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    });

    vector<vector<int>> up_left(n+1, vector(m+1, iInf)),
                        down_right(n+1, vector(m+1, iInf)),
                        up_right(n+1, vector(m+1, -iInf)),
                        down_left(n+1, vector(m+1, -iInf));
    forx(i, 0, n)
        forx(j, 0, m)
            up_left[i + 1][j + 1] = min({ up_left[i][j + 1], up_left[i + 1][j], a[i][j] });
    
    dfor(i, n-1, 0)
        forx(j, 0, m)
            down_left[i][j+1] = max({down_left[i+1][j+1], down_left[i][j], a[i][j]});

    forx(i, 0, n)
        dfor(j, m-1, 0)
            up_right[i+1][j] = max({up_right[i][j], up_right[i+1][j+1], a[i][j]});

    dfor(i, n-1, 0)
        dfor(j, m-1, 0)
            down_right[i][j] = min({down_right[i+1][j], down_right[i][j+1], a[i][j]});

    forx(first_blue, 1, n) {
        forx(cut, 1, m) {
            if (up_left[first_blue][cut] > down_left[first_blue][cut]
                &&
                down_right[first_blue][cut] > up_right[first_blue][cut]) 
            {
                cout << "YES\n";
                string res(n, 'B');
                forx(i, 0, first_blue) {
                    res[a[i][m]] = 'R';
                }
                cout << res << " " << cut << "\n";
                return;
            }
        }
    }
    cout << "NIE\n";
}


int main()
{
    gottagofast();
    int z = 1;
#if TESTSETS
    cin >> z;
#endif 
    forx(case_num, 0, z) {
        echo(c::cyan, "---------------");
        echo(c::cyan, "Test #", case_num - nn - ns);
        Input();
        echo(c::green, "Result:");
        Solve();
        echo("");
    }
}