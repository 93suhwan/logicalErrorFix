/*学习古代文章，诗词
出师表 三国·诸葛亮

先帝创业未半而中道崩殂，今天下三分，益州疲弊，此诚危急存亡之秋也。然侍卫之臣不懈于内，忠志之士忘身于外者，盖追先帝之殊遇，欲报之于陛下也。诚宜开张圣听，以光先帝遗德，恢弘志士之气，不宜妄自菲薄，引喻失义，以塞忠谏之路也。

宫中府中，俱为一体；陟罚臧否，不宜异同：若有作奸犯科及为忠善者，宜付有司论其刑赏，以昭陛下平明之理；不宜偏私，使内外异法也。

侍中、侍郎郭攸之、费祎、董允等，此皆良实，志虑忠纯，是以先帝简拔以遗陛下：愚以为宫中之事，事无大小，悉以咨之，然后施行，必能裨补阙漏，有所广益。

将军向宠，性行淑均，晓畅军事，试用于昔日，先帝称之曰“能”，是以众议举宠为督：愚以为营中之事，悉以咨之，必能使行阵和睦，优劣得所。

亲贤臣，远小人，此先汉所以兴隆也；亲小人，远贤臣，此后汉所以倾颓也。先帝在时，每与臣论此事，未尝不叹息痛恨于桓、灵也。侍中、尚书、长史、参军，此悉贞良死节之臣，愿陛下亲之信之，则汉室之隆，可计日而待也。

臣本布衣，躬耕于南阳，苟全性命于乱世，不求闻达于诸侯。先帝不以臣卑鄙，猥自枉屈，三顾臣于草庐之中，咨臣以当世之事，由是感激，遂许先帝以驱驰。后值倾覆，受任于败军之际，奉命于危难之间：尔来二十有一年矣。

先帝知臣谨慎，故临崩寄臣以大事也。受命以来，夙夜忧叹，恐托付不效，以伤先帝之明；故五月渡泸，深入不毛。今南方已定，兵甲已足，当奖率三军，北定中原，庶竭驽钝，攘除奸凶，兴复汉室，还于旧都。此臣所以报先帝而忠陛下之职分也。至于斟酌损益，进尽忠言，则攸之、祎、允之任也。

愿陛下托臣以讨贼兴复之效，不效，则治臣之罪，以告先帝之灵。若无兴德之言，则责攸之、祎、允等之慢，以彰其咎；陛下亦宜自谋，以咨诹善道，察纳雅言，深追先帝遗诏。臣不胜受恩感激。

今当远离，临表涕零，不知所言。
*/
//Generated at 2021-10-12 15:26:19 UTC+8
//Created by Alphagocc
#ifndef TYPE_HPP
#define TYPE_HPP
#include <type_traits>
#ifndef __cpp_lib_void_t
namespace std
{
template <typename...> using void_t = void;
}
#endif
template <typename T, typename _ = void> struct is_container : std::false_type
{};
template <typename... Ts> struct is_container_helper
{};
template <typename T>
struct is_container<T,
    typename std::conditional<false,
        is_container_helper<decltype(std::declval<T>().size()),
            decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end()),
            decltype(std::declval<T>().cbegin()),
            decltype(std::declval<T>().cend())>,
        void>::type> : public std::true_type
{};
#endif
#include <bits/stdc++.h>
#define FORCE_INLINE __inline__ __attribute__((always_inline))
class IO
{
    static const int bufSize = 1 << 20;

    char inBuf[bufSize], outBuf[bufSize];
    char *ip1 = inBuf, *ip2 = inBuf;
    int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;
    FORCE_INLINE int gc()
    {
        return ip1 == ip2
                && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin),
                    ip1 == ip2)
            ? (goodReadBit = 0, EOF)
            : *ip1++;
    }
    template <typename T> FORCE_INLINE void __RI(T &x)
    {
        int ch = gc(), neg = 1;
        x = 0;
        for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = gc()) {}
        if (ch == EOF) return;
        if (ch == '-') neg = -1, ch = gc();
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - 48) * neg;
    }
    template <typename T> FORCE_INLINE void __RC(T &x)
    {
        int ch;
        while (isspace(ch = gc())) {}
        if (ch == EOF) return;
        x = ch;
    }
    FORCE_INLINE void __RS(std::string &x)
    {
        char ch;
        x.clear();
        for (ch = gc(); isspace(ch); ch = gc()) {}
        if (ch == EOF) return;
        for (; !isspace(ch) && ch != EOF; ch = gc()) x.push_back(ch);
    }

public:
    FORCE_INLINE IO &R(char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(unsigned char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(std::string &x) { return __RS(x), (*this); }
    template <typename T1, typename T2> FORCE_INLINE IO &R(std::pair<T1, T2> &x)
    {
        return R(x.first), R(x.second), (*this);
    }
    template <typename T, typename... Args> FORCE_INLINE IO &RA(T *a, int n)
    {
        for (int i = 0; i < n; ++i) R(a[i]);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &R(T &x, Args &...args)
    {
        return R(x), R(args...), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &RA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; ++i) RA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        R(T &x)
    {
        return __RI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &R(
        T &x)
    {
        for (auto &i : x) R(i);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().read())>>::value,
        IO>::type &
        R(T &x)
    {
        return x.read(), (*this);
    }

private:
    char space = ' ';
    FORCE_INLINE void pc(const char &x)
    {
        if (op1 == op2) flush();
        outBuf[++op1] = x;
    }
    template <typename T> FORCE_INLINE void __WI(T x)
    {
        static char buf[sizeof(T) * 16 / 5];
        static int len = -1;
        if (x >= 0) {
            do {
                buf[++len] = x % 10 + 48, x /= 10;
            } while (x);
        } else {
            pc('-');
            do {
                buf[++len] = -(x % 10) + 48, x /= 10;
            } while (x);
        }
        while (len >= 0) { pc(buf[len]), --len; }
    }

public:
    FORCE_INLINE void flush() { fwrite(outBuf, 1, op1 + 1, stdout), op1 = -1; }
    FORCE_INLINE IO &W(const char &x) { return pc(x), (*this); }
    FORCE_INLINE IO &W(const char *x)
    {
        while (*x != '\0') pc(*(x++));
        return (*this);
    }
    FORCE_INLINE IO &W(const std::string &x) { return W(x.c_str()), (*this); }
    template <typename T1, typename T2>
    FORCE_INLINE IO &W(const std::pair<T1, T2> &x)
    {
        WS(x.first);
        W(x.second);
        return (*this);
    }
    FORCE_INLINE IO &WL() { return W('\n'), (*this); }
    template <typename T> FORCE_INLINE IO &WL(const T &x)
    {
        return W(x), W('\n'), (*this);
    }
    FORCE_INLINE IO &WS() { return W(space), (*this); }
    template <typename T> FORCE_INLINE IO &WS(const T &x)
    {
        return W(x), W(space), (*this);
    }
    template <typename T> FORCE_INLINE IO &WA(T *a, int n)
    {
        for (int i = 0; i < n; i++) WS(a[i]);
        WL();
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &W(const T &x, const Args &...args)
    {
        W(x), W(space), W(args...);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WS(const T &x, const Args &...args)
    {
        return W(x), W(space), W(args...), W(space), (*this);
    }
    template <typename... Args> FORCE_INLINE IO &WL(const Args &...args)
    {
        return W(args...), W('\n'), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; i++) WA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        W(const T &x)
    {
        return __WI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &W(
        const T &x)
    {

        for (auto &i : x) WS(i);
        WL();
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().write())>>::value,
        IO>::type &
        W(const T &x)
    {
        return x.write(), (*this);
    }
    template <typename T> FORCE_INLINE IO &operator>>(T &x)
    {
        R(x);
        return (*this);
    }
    template <typename T> FORCE_INLINE IO &operator<<(const T &x)
    {
        W(x);
        return (*this);
    }
    int good() { return goodReadBit; }
    IO() {}
    ~IO() { flush(); }
} io;
#undef FORCE_INLINE

#ifndef UTIL_HPP
#define UTIL_HPP
#include <bits/stdc++.h>
#define var auto
#define ALL(x) x.begin(), x.end()
const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;
#define If(x, y, z) ((x) ? (y) : (z))
#endif
#include "windows.h"
// https://www.zhihu.com/question/378525362/answer/1078276038;

constexpr unsigned int CreateSeed(
    const char *str, const unsigned int initial_result = 0)
{
    return *str == 0
        ? initial_result
        : CreateSeed(str + 1, ((initial_result << 8ULL) + *str) & UINT_MAX);
}

template <typename... RemainingStrings>
constexpr unsigned int CreateSeed(
    const char *first_str, const RemainingStrings &...remaining_strs)
{
    return CreateSeed(first_str, CreateSeed(remaining_strs...));
}

template <unsigned int Seed> struct Random
{
    static constexpr unsigned int value
        = (134775813ULL * Seed + 1ULL) & UINT_MAX;
    using next = Random<value>;
};
constexpr bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}
using namespace std;
constexpr unsigned int kSeed = CreateSeed(__TIME__, __DATE__);
constexpr int randomPrimeInCompileTime()
{
    int x = Random<kSeed>::value;
    x &= 0x3fffffff;
    if (x < int(1e8)) x += 1e8;
    while (!isPrime(x)) x++;
    return x;
}
int CodeforcesRandSeed()
{
    int x = GetCurrentProcessId();
    x ^= (int64_t)GetProcessHeap();
    x ^= (int64_t)HeapAlloc(GetProcessHeap(), 0, 1);
    auto dummy = new char;
    x ^= (int64_t)dummy;
    x ^= random_device{}();
    x ^= chrono::high_resolution_clock().now().time_since_epoch().count();
    return x;
}
mt19937_64 rng(CodeforcesRandSeed());
int randomPrime()
{
    int x = Random<kSeed>::value;
    x &= 0x3fffffff;
    if (x < int(1e8)) x += 1e8;
    while (!isPrime(x)) x++;
    return x;
}
vector<int> zAlgo(string s)
{
    int n = s.length();
    vector<int> z(n + 1);
    z[0] = n;
    int j = 0;
    for (int i = 1; i <= n;) {
        for (; i + j < n && s[i + j] == s[j]; j++)
            ;
        if (z[i] = j) {
            int k;
            for (k = 1; k + z[k] < z[i]; k++) z[i + k] = z[k];
            i += k;
            j -= k;
        } else
            i++;
    }
    return z;
}
const int Ps[] = { 257, 65537, 17 };
uniform_int_distribution<int> dis(0, sizeof(Ps) / sizeof(Ps[0]) - 1);
namespace Math
{
template <typename T, typename T2> T qpow(T a, T2 b, const int &MOD)
{
    T ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}
template <typename T> T exgcd(T l, T r, T &x, T &y)
{
    if (!r) {
        x = 1, y = 0;
        return l;
    } else {
        int d = exgcd(r, l % r, y, x);
        y -= l / r * x;
        return d;
    }
}
template <typename T> T inv(T a, const int &MOD)
{
    return qpow(a, MOD - 2, MOD);
}
template <typename T> T exinv(T a, const int &MOD)
{
    T x, y;
    exgcd(a, MOD, x, y);
    x %= MOD;
    return x + ((x >> (sizeof(T) * 8 - 1)) & MOD);
}
// Only Use Signed Integer
template <typename T, T MOD> struct ModInt
{
    T x;
    ModInt(T x = 0)
        : x(x)
    {
        while (x < 0) x += MOD;
    }
    ModInt<T, MOD> operator+=(const ModInt<T, MOD> &y)
    {
        x += y.x - MOD;
        x += (x >> (sizeof(T) * 8 - 1)) & MOD;
        return (*this);
    }
    ModInt<T, MOD> operator-=(const ModInt<T, MOD> &y)
    {
        x = x - y.x;
        x += (x >> (sizeof(T) * 8 - 1)) & MOD;
        return (*this);
    }
    ModInt<T, MOD> operator*=(const ModInt<T, MOD> &y)
    {
        x = x * y.x % MOD;
        return (*this);
    }
    ModInt<T, MOD> operator/=(const ModInt<T, MOD> &y)
    {
        x = x * inv(y.x, MOD) % MOD;
        return (*this);
    }
    ModInt<T, MOD> pow(int64_t p) { return x = qpow(x, p, MOD), *this; }
    void write() const { io.W(x); }
};
template <typename T, T MOD>
ModInt<T, MOD> operator+(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a += b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator-(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a -= b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator*(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a *= b;
    return a;
}
template <typename T, T MOD>
ModInt<T, MOD> operator/(ModInt<T, MOD> a, const ModInt<T, MOD> &b)
{
    a /= b;
    return a;
}
template <typename T, T MOD>
bool operator==(const ModInt<T, MOD> &a, const ModInt<T, MOD> &b)
{
    return a.x == b.x;
}
}
const int MOD1 = randomPrimeInCompileTime(), MOD2 = randomPrime();
struct Hash2
{
    using mint = Math::ModInt<int64_t, MOD1>;
    using H = Hash2;
    mint h1;
    int64_t h2;
    Hash2(mint h1 = 0, int64_t h2 = 0)
        : h1(h1)
        , h2(h2)
    {}
    H &operator+=(const H &y)
    {
        h2 += y.h2 - MOD2;
        h2 += (h2 >> (sizeof(int64_t) * 8 - 1)) & MOD2;
        h1 += y.h1;
        return *this;
    }
    H &operator-=(const H &y)
    {
        h2 -= y.h2;
        h2 += (h2 >> (sizeof(int64_t) * 8 - 1)) & MOD2;
        h1 -= y.h1;
        return *this;
    }
    H &operator*=(const H &y)
    {
        h1 = h1 * y.h1;
        h2 = h2 * y.h2 % MOD2;
        return *this;
    }
};
Hash2 operator+(Hash2 a, const Hash2 &b)
{
    a += b;
    return a;
}
Hash2 operator-(Hash2 a, const Hash2 &b)
{
    a -= b;
    return a;
}
Hash2 operator*(Hash2 a, const Hash2 &b)
{
    a *= b;
    return a;
}
bool operator==(const Hash2 &a, const Hash2 &b)
{
    return a.h1 == b.h1 && a.h2 == b.h2;
}
struct RollingHash
{
    using H = Hash2;
    int n;
    vector<H> pw, hs;
    RollingHash(string s, int P1, int P2)
    {
        n = s.size();
        auto P = H(P1, P2);
        pw.resize(n + 1, H(0, 0));
        hs = pw;
        pw[0] = H(1, 1);
        for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * P;
        for (int i = 0; i < n; i++)
            hs[i + 1] = hs[i] * P + H(s[i] - '0', s[i] - '0');
    }
    H getHash(int l, int r) { return hs[r] - hs[l] * pw[r - l]; }
};

int main()
{
    string s, t;
    io >> s >> t;
    auto z = zAlgo(t + "$" + s);
    int P1 = 10, P2 = 10;
    auto hs = RollingHash(s, P1, P2);
    auto ht = RollingHash(t, P1, P2);
    int n = s.size(), m = t.size();
    auto want = ht.getHash(0, m);
    vector<int> lcp(n);
    for (int i = 0; i < n; i++) { lcp[i] = min(z[i + m + 1], m); }
    auto test = [&](int l1, int r1, int l2, int r2) {
        /* io.WL(l1 + 1, r1, l2 + 1, r2);
        io.WL(hs.getHash(l1, r1).h1, hs.getHash(l1, r1).h2);
        io.WL(hs.getHash(l2, r2).h1, hs.getHash(l2, r2).h2);
        io.WL(want.h1, want.h2); */
        if (hs.getHash(l1, r1) + hs.getHash(l2, r2) == want) {
            io.WL(l1 + 1, r1).WL(l2 + 1, r2);
            exit(0);
        }
    };
    auto check = [&](int l, int r, int k) {
        if (r > n) return;
        // io.WL(l, r, k);
        if (k > 0) {
            if (r + k <= n) test(l, r, r, r + k);
            if (l - k >= 0) test(l - k, l, l, r);
        }
    };
    for (int i = 0; i < n; i++) {
        {
            check(i, i + m, m - lcp[i]);
            check(i, i + m, m - lcp[i] - 1);
        }
        if (m > 1) {
            check(i, i + m - 1, m);
            check(i, i + m - 1, m - 1);
        }
    }
    return 0;
}