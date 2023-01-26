#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define _GLIBCXX_DEBUG_PEDANTIC
#endif
//#define NOGNU
#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
#pragma GCC target("avx2")
// #pragma GCC target("sse4")
// #pragma GCC target("sse2")
#pragma GCC target("bmi2")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <immintrin.h>
#ifdef IACA
#include <iacaMarks.h>
#else
#define IACA_START
#define IACA_END
#endif
// #define FILENAME "delivery"
#ifndef NOGNU
    #include <ext/rope>
    #include <ext/pb_ds/assoc_container.hpp>
#endif // NOGNU
#define lambda(body, ...) [&](__VA_ARGS__) { return body; }
#define vlambda(body, ...) lambda(body, __VA_ARGS__, auto&&...)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define eb emplace_back
#define unires(x) x.resize(unique(all(x)) - x.begin())
#define ll long long
#define yesno(x) ((x) ? "YES" : "NO")
#define _ _ __attribute__((unused))

using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const unsigned ll M1 = 4294967291, M2 = 4294967279, M = 998244353;
const ld EPS = 1e-8;

#ifndef M_PI
    const ld M_PI = acos(-1);
#endif // M_PI

using namespace std;

#ifndef NOGNU
    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    template<class K, class T, class Cmp = less<K>>
    using ordered_map = tree<K, T, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

    template<class T, class Cmp = less<T>>
    using ordered_set = ordered_map<T, null_type, Cmp>;
#endif

void run();

template<bool neg>
struct Inf {
    constexpr Inf() {}
    template<class T>
    constexpr operator T() const {
        if constexpr (neg) {
            return numeric_limits<T>::min() / 2;
        } else {
            return numeric_limits<T>::max() / 2;
        }
    }
    Inf &operator=(const Inf&) = delete;
    Inf &operator=(Inf&&) = delete;
    Inf(const Inf&) = delete;
    Inf(Inf&&) = delete;
    Inf<!neg> operator-() const {
        return {};
    }
};

Inf<0> inf;

template<class T1, class T2>
inline bool mini(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1, class T2>
inline bool maxi(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

mt19937 rnd(0);

signed main() {
    #if defined FILENAME && !defined STDIO && !defined LOCAL
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    #endif // FILENAME
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef LOCAL
    rnd.seed(random_device{}());
    #endif
    cout << setprecision(11) << fixed;
    #ifdef PRINTTIME
        auto start = clock();
    #endif
    run();
    #ifdef PRINTTIME
        cout << "\ntime = " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n";
    #endif
    return 0;
}

#define rand rnd

template<class T>
struct is_continer {
 private:
    static void detect(...);
    template<class U>
    static decltype(declval<U>().begin()) detect(const U&);
 public:
    static const bool value = !is_same<decltype(detect(declval<T>())), void>::value;
};

template<class T>
struct is_std_array {
    static const bool value = 0;
};

template<class T, size_t sz>
struct is_std_array<array<T, sz>> {
    static const bool value = 1;
};

template<class T>
struct is_tuple_like {
 private:
    static void detect(...);
    template<class U>
    static typename enable_if<(bool) tuple_size<U>::value, int>::type detect(const U&);
 public:
    static const bool value = !is_same<decltype(detect(declval<T>())), void>::value;
};

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value
#ifndef NOGNU
    && !is_same<T, rope<char>>::value
#endif
, ostream>::type&
operator<<(ostream &out, const T &arr) {
    bool first = 1;
    for (auto &&x : arr) {
        if (!first) {
            if constexpr (
                (is_continer<typename T::value_type>::value && !is_same<typename T::value_type, string>::value)
                || is_tuple_like<typename T::value_type>::value) {
                out << '\n';
            } else {
                out << ' ';
            }
        } else {
            first = 0;
        }
        out << x;
    }
    return out;
}

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value
#ifndef NOGNU
    && !is_same<T, rope<char>>::value
#endif
, istream>::type&
operator>>(istream &in, T &arr) {
    for (auto &x : arr)
        in >> x;
    return in;
}

template<class T, size_t pos>
void read_tuple(istream &in, T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        in >> get<pos>(x);
        read_tuple<T, pos + 1>(in, x);
    }
}

template<class T, size_t pos = 0>
typename enable_if<is_tuple_like<T>::value && !is_std_array<T>::value, istream>::type&
operator>>(istream &in, T &x) {
    read_tuple<T, 0>(in, x);
    return in;
}

template<class T, size_t pos>
void write_tuple(ostream &out, const T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        if constexpr (pos != 0)
            out << " ";
        out << get<pos>(x);
        write_tuple<T, pos + 1>(out, x);
    }
}

template<class T>
typename enable_if<is_tuple_like<T>::value && !is_std_array<T>::value, ostream>::type&
operator<<(ostream &out, const T &x) {
    write_tuple<T, 0>(out, x);
    return out;
}

template<class T, class... Args>
T input(Args&&... args) {
    T x(args...);
    cin >> x;
    return x;
}

namespace segtree {

#ifdef LOCAL
#pragma GCC diagnostic ignored "-Winaccessible-base"
#endif

struct DoNothingFunc {
    template<class... Args>
    void operator()(Args&&... args) const {}
};

struct AssignFunc {
    template<class T, class U, class... Args>
    void operator()(T &x, U &&y, Args&&...) const {
        x = forward<U>(y);
    }
};

template<class F, class Res, class... Args>
inline 
typename enable_if<
    is_void_v<decltype(declval<F>()(declval<Res&>(), declval<Args>()...))>,
    void
>::type
assign_or_call(F &f, Res &res, Args&&... args) {
    f(res, forward<Args>(args)...);
}

template<class F, class Res, class... Args>
inline 
typename enable_if<
    !is_void_v<decltype(declval<F>()(declval<Args>()...))>,
    void
>::type
assign_or_call(F &f, Res &res, Args&&... args) {
    res = f(forward<Args>(args)...);
}

template<int priority, class calc_t, class recalc_t, class join_t, class Self>
struct PointUpdatePolicyType {
    static const int update_priority = priority;
    static const int init_priority = numeric_limits<int>::min();
    calc_t calc;
    recalc_t recalc;
    join_t join;
    template<class F, class Policy>
    static auto select(Policy policy) {
        if constexpr (is_default_constructible<F>::value)
            return F();
        else
            return policy.template get<F>();
    }
    template<class Policy>
    PointUpdatePolicyType(Policy policy)
        : calc(select<calc_t>(policy))
        , recalc(select<recalc_t>(policy))
        , join(select<join_t>(policy)) {}
    PointUpdatePolicyType(const PointUpdatePolicyType &) = default;
    template<class... Args>
    void upd_impl(size_t p, size_t v, size_t l, size_t r, Args&&... args) {
        auto self = static_cast<Self *>(this);
        self->push(v, l, r);
        assign_or_call(recalc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
        if (r - l == 1) {
            assign_or_call(calc, self->get_val(self->a[v]), forward<Args>(args)..., l, r);
            return;
        }
        size_t c = (l + r) / 2;
        size_t left = self->get_left(v, l, r);
        size_t right = self->get_right(v, l, r);
        if (p < c)
            upd_impl(p, left, l, c, forward<Args>(args)...);
        else
            upd_impl(p, right, c, r, forward<Args>(args)...);
        assign_or_call(
            join,
            self->get_val(self->a[v]),
            self->get_val(self->a[left]),
            self->get_val(self->a[right]),
            forward<Args>(args)...,
            l, r);
    }
    template<class... Args>
    void upd(size_t p, Args&&... args) {
        auto self = static_cast<Self *>(this);
        upd_impl(p, self->get_root(), 0, self->n, forward<Args>(args)...);
    }
    void push(size_t, size_t, size_t) {}
};

template<class recalc_t, int priority = 0>
struct PathUpdatePolicy {
    recalc_t recalc;
    template<class T>
    T get() {
        return recalc;
    }
    PathUpdatePolicy(recalc_t recalc): recalc(recalc) {}
    template<class Self>
    using type = PointUpdatePolicyType<
        priority,
        DoNothingFunc,
        recalc_t,
        DoNothingFunc,
        Self
    >;
};

template<class join_t, class convert_t, int priority = 0>
struct JoinUpdatePolicy {
    join_t join;
    convert_t convert;
    template<class T>
    T get() {
        if constexpr (is_same_v<T, join_t>)
            return T(join);
        else
            return T(convert);
    }
    JoinUpdatePolicy(join_t join, convert_t convert): join(join), convert(convert) {}
    template<class Self>
    using type = PointUpdatePolicyType<
        priority,
        convert_t,
        DoNothingFunc,
        join_t,
        Self
    >;
};

template<int priority, class gen_t, class Self>
struct SegTreeInitType {
    static const int init_priority = priority;
    static const int update_priority = numeric_limits<int>::min();
    void push(size_t, size_t, size_t) {}
    gen_t gen;
    template<class Policy>
    SegTreeInitType(Policy policy): gen(policy.template get<gen_t>()) {}
    void build(size_t v, size_t l, size_t r) {
        auto self = static_cast<Self *>(this);
        if constexpr (!is_invocable_v<gen_t, size_t>) {
            self->get_val(self->a[v]) = init(l, r);
        }
        if (r - l == 1) {
            if constexpr (is_invocable_v<gen_t, size_t> && !is_invocable_v<gen_t, size_t,  size_t>) {
                self->get_val(self->a[v]) = gen(l);
            }
        } else {
            size_t c = (l + r) / 2;
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            build(left, l, c);
            build(right, c, r);
            if constexpr (is_invocable_v<gen_t, size_t>) {
                self->join(
                    self->get_val(self->a[v]),
                    self->get_val(self->a[left]),
                    self->get_val(self->a[right]));
            }
        }
    }
    void init() {
        auto self = static_cast<Self *>(this);
        build(self->get_root(), 0, self->n);
    }
    auto init(size_t l, size_t r) {
        if constexpr (is_invocable_v<gen_t, size_t, size_t>)
            return gen(l, r);
        else
            return gen();
    }
};

template<class gen_t>
struct InitPolicy {
    gen_t gen;
    InitPolicy(gen_t gen): gen(gen) {}
    template<class T>
    T get() {
        return gen;
    }
    template<class Self>
    using type = SegTreeInitType<0, gen_t, Self>;
};

struct IdentityFunc {
    template<class T, class... Args>
    const T &operator()(const T &x, Args&&...) {
        return x;
    }
};

template<class join_t, class identity_t, class convert_t = IdentityFunc>
struct GetPolicy {
    join_t join;
    identity_t identity;
    convert_t convert;
    template<class T>
    T get() {
        if constexpr (is_same_v<T, join_t>)
            return join;
        else if constexpr (is_same_v<T, identity_t>)
            return identity;
    }
    GetPolicy(join_t join, identity_t identity, convert_t convert = convert_t()):
        join(join),
        identity(identity),
        convert(convert) {}
    template<class Self>
    struct type
        : public PointUpdatePolicyType<
            -1,
            AssignFunc,
            DoNothingFunc,
            join_t,
            Self
        >
        , public SegTreeInitType<-1, identity_t, Self>
    {
        static const int init_priority = -1;
        static const int update_priority = -1;
        GetPolicy policy;
        type(GetPolicy policy)
            : PointUpdatePolicyType<
                -1,
                AssignFunc,
                DoNothingFunc,
                join_t,
                Self
            >(policy)
            , SegTreeInitType<-1, identity_t, Self>(policy)
            , policy(policy) {}
        template<class... Args>
        auto get_impl(size_t ql, size_t qr, size_t v, size_t l, size_t r, const Args&... args) {
            auto self = static_cast<Self *>(this);
            if (qr <= l || r <= ql)
                return policy.identity(args..., l, r);
            self->push(v, l, r);
            if (ql <= l && r <= qr)
                return policy.convert(self->get_val(self->a[v]), args..., l, r);
            size_t c = (l + r) / 2;
            return policy.join(
                get_impl(ql, qr, self->get_left(v, l, r), l, c, args...),
                get_impl(ql, qr, self->get_right(v, l, r), c, r, args...),
                args..., l, r);
        }
        template<class... Args>
        auto get(size_t ql, size_t qr, const Args&... args) {
            auto self = static_cast<Self *>(this);
            return get_impl(ql, qr, self->get_root(), 0, self->n, args...);
        }
        void push(size_t, size_t, size_t) {}
    };
};

template<class push_t, class balance_t, class calc_t>
struct MassUpdatePolicy {
    push_t push;
    balance_t balance;
    calc_t calc;
    MassUpdatePolicy(push_t push, balance_t balance, calc_t calc):
        push(push),
        balance(balance),
        calc(calc) {}
    template<class Self>
    struct type {
        static const int init_priority = numeric_limits<int>::min();
        static const int update_priority = numeric_limits<int>::min();
        MassUpdatePolicy policy;
        type(MassUpdatePolicy policy): policy(policy) {}
        void push(size_t v, size_t l, size_t r) {
            auto self = static_cast<Self *>(this);
            if (r - l != 1) {
                auto left = self->get_left(v, l, r);
                auto right = self->get_right(v, l, r);
                size_t c = (l + r) / 2;
                policy.push(self->get_val(self->a[left]), l, c, self->get_val(self->a[v]), l, r);
                policy.push(self->get_val(self->a[right]), c, r, self->get_val(self->a[v]), l, r);
            }
            policy.balance(self->get_val(self->a[v]), l, r);
        }
        template<class... Args>
        void mass_upd_impl(size_t ql, size_t qr, size_t v, size_t l, size_t r, Args&&... args) {
            auto self = static_cast<Self *>(this);
            if (qr <= l || r <= ql)
                return;
            self->push(v, l, r);
            if (ql <= l && r <= qr) {
                policy.calc(self->get_val(self->a[v]), args..., l, r);
                return;
            }
            size_t c = (l + r) / 2;
            mass_upd_impl(ql, qr, self->get_left(v, l, r), l, c, args...);
            mass_upd_impl(ql, qr, self->get_right(v, l, r), c, r, args...);
            auto left = self->get_left(v, l, r);
            auto right = self->get_right(v, l, r);
            self->join(self->get_val(self->a[v]), self->get_val(self->a[left]), self->get_val(self->a[right]));
        }
        template<class... Args>
        void mass_upd(size_t ql, size_t qr, Args&&... args) {
            auto self = static_cast<Self *>(this);
            mass_upd_impl(ql, qr, self->get_root(), 0, self->n, args...);
        }
    };
};

struct BaseSegTree {
    void init() {}
    template<class... Args>
    void upd(Args&&...) {}
    DoNothingFunc join;
};

#define SEG_TREE_HELPERS(SegTree) \
    void push(size_t v, size_t l, size_t r) { \
        (Policies<SegTree<T, Policies...>>::push(v, l, r), ...); \
    } \
    template<class... Args> \
    void upd(size_t p, Args&&... args) { \
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::update_priority...}); \
        auto select = []<class X>(X x) { \
            if constexpr (X::update_priority >= max_prior) { \
                return x; \
            } else { \
                return BaseSegTree(); \
            } \
        }; \
        (decltype(select(declval<Policies<SegTree<T, Policies...>>>()))::upd(p, forward<Args>(args)...), ...); \
    } \
    template<class P> \
    typename P::template type<SegTree<T, Policies...>> &as(const P&) { \
        return static_cast<typename P::template type<SegTree<T, Policies...>> &>(*this); \
    } \
    template<class... Args> \
    void join(T &res, const T &a, const T &b, Args&&... args) { \
        constexpr auto max_prior = max({Policies<SegTree<T, Policies...>>::update_priority...}); \
        auto select = []<class X>(X x) { \
            if constexpr (X::update_priority >= max_prior) { \
                return x; \
            } else { \
                return BaseSegTree(); \
            } \
        }; \
        (assign_or_call( \
            static_cast<decltype(select(declval<Policies<SegTree<T, Policies...>>>())) *>(this)->join, \
            res, a, b, args...), ...); \
    } \
    auto init(size_t l, size_t r) { \
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::init_priority...}); \
        auto select = []<class X, class... Args>(auto select, X x, Args... args) { \
            if constexpr (X::init_priority >= max_prior) { \
                return x; \
            } else { \
                return select(select, args...); \
            } \
        }; \
        return decltype(select(select, declval<Policies<SegTree<T, Policies...>>>()...))::init(l, r); \
    } \

template<class T, template<class> class... Policies>
struct SegTree: BaseSegTree, public Policies<SegTree<T, Policies...>>... {
    size_t n;
    vector<T> a;
    SegTree(size_t n, Policies<SegTree<T, Policies...>>... policies)
        : Policies<SegTree<T, Policies...>>(policies)...
        , n(n)
        , a(n * 4)
    {
        constexpr int max_prior = max({Policies<SegTree<T, Policies...>>::init_priority...});
        auto select = []<class X>(X x) {
            if constexpr (X::init_priority >= max_prior) {
                return x;
            } else {
                return BaseSegTree();
            }
        };
        (decltype(select(policies))::init(), ...);
    }
    T &get_val(T &x) {
        return x;
    }
    size_t get_left(size_t v, size_t, size_t) const {
        return v * 2 + 1;
    }
    size_t get_right(size_t v, size_t, size_t) const {
        return v * 2 + 2;
    }
    size_t get_root() const {
        return 0;
    }
    SEG_TREE_HELPERS(SegTree)
};

template<class T, class... Policies>
SegTree<T, Policies::template type...> make_segtree(size_t n, Policies... policies) {
    return SegTree<T, Policies::template type...>(
        n,
        typename Policies::template type<SegTree<T, Policies::template type...>>(policies)...);
}

template<class T, template<class> class... Policies>
struct LazySegTree: BaseSegTree, public Policies<LazySegTree<T, Policies...>>... {
    struct Node {
        constexpr static unsigned null = numeric_limits<unsigned>::max();
        unsigned left = null, right = null;
        T val;
        Node(T &&val): val(val) {}
    };
    size_t n;
    vector<Node> a;
    LazySegTree(size_t n, Policies<LazySegTree<T, Policies...>>... policies)
        : Policies<LazySegTree<T, Policies...>>(policies)...
        , n(n)
    {}
    T &get_val(Node &node) {
        return node.val;
    }
    size_t get_left(size_t v, size_t l, size_t r) {
        if (a[v].left == Node::null) {
            a[v].left = a.size();
            a.eb(init(l, r));
        }
        return a[v].left;
    }
    size_t get_right(size_t v, size_t l, size_t r) {
        if (a[v].right == Node::null) {
            a[v].right = a.size();
            a.eb(init(l, r));
        }
        return a[v].right;
    }
    size_t get_root() {
        if (a.empty())
            a.eb(init(0, n));
        return 0;
    }
    SEG_TREE_HELPERS(LazySegTree)
};

template<class T, class... Policies>
LazySegTree<T, Policies::template type...> make_lazy_segtree(size_t n, Policies... policies) {
    return LazySegTree<T, Policies::template type...>(
        n,
        typename Policies::template type<LazySegTree<T, Policies::template type...>>(policies)...);
}

#undef SEG_TREE_HELPERS

#ifdef LOCAL
#pragma GCC diagnostic pop
#endif

}; // namespace segtree

#if !defined NOGNU && __x86_64__

namespace std {

template<>
struct make_unsigned<__int128> {
    using type = unsigned __int128;
};

template<>
struct make_unsigned<unsigned __int128> {
    using type = unsigned __int128;
};

}; // namespace std

#endif

template<class T_ = int, make_unsigned_t<T_> mod = M, class U_ = ll>
struct ModInt {
    using T = make_unsigned_t<T_>;
    using U = make_unsigned_t<U_>;
    static_assert(sizeof(U) > sizeof(T));
    T x;
    constexpr ModInt() {}
    constexpr ModInt(T x): x(x) {}
    template<
        class T2_,
        class U2_,
        class = typename enable_if<sizeof(T) == sizeof(T2_), void>::type
    >
    constexpr ModInt(ModInt<T2_, mod, U2_> other): x(other.x) {}
    bool operator==(ModInt other) const {
        return x == other.x;
    }
    bool operator!=(ModInt other) const {
        return x != other.x;
    }
    bool operator<(ModInt other) const {
        return x < other.x;
    }
    constexpr ModInt operator+(ModInt other) const {
        using imm_type = conditional_t<U(mod) + U(mod) == U(mod + mod), T, U>;
        auto res = imm_type(x) + imm_type(other.x);
        res -= res >= mod ? mod : 0;
        return ModInt(res);
    }
    constexpr ModInt &operator+=(ModInt other) {
        return *this = *this + other;
    }
    ModInt operator-() const {
        return ModInt(x ? mod - x : 0);
    }
    constexpr ModInt operator-(ModInt other) const {
        return *this + -other;
    }
    constexpr ModInt &operator-=(ModInt other) {
        return *this = *this - other;
    }
    constexpr ModInt operator*(ModInt other) const {
        using imm_type = conditional_t<U(mod) * U(mod) == U(mod * mod), T, U>;
        auto res = imm_type(x) * imm_type(other.x);
        return ModInt(res % mod);
    }
    constexpr ModInt &operator*=(ModInt other) {
        return *this = *this * other;
    }
    template<class Int>
    constexpr ModInt pow(Int p) const {
        if (!p) {
            return 1;
        } else if (p & 1) {
            return *this * pow(p - 1);
        } else {
            auto t = pow(p >> 1);
            return t * t;
        }
    }
    constexpr ModInt inv() const {
        return pow(mod - 2);
    }
    constexpr ModInt operator/(ModInt other) const {
        return *this * other.inv();
    }
    constexpr ModInt &operator/=(ModInt other) {
        return *this = *this / other;
    }
};

template<class F>
inline auto cond_cmp(F &&f) {
    return [f]<class A, class B>(const A &a, const B &b)->bool {
        if constexpr (is_same_v<A, monostate>) {
            return 0;
        } else if constexpr (is_same_v<B, monostate>) {
            return !f(a);
        } else {
            return f(a) < f(b);
        }
    };
}

template<class Int>
struct range {
    using value_type = Int;
    Int first, last;
    range(Int last): first(0), last(last) {}
    range(Int first, Int last): first(first), last(last) {}
    struct iterator {
        using difference_type = make_signed_t<Int>;
        using value_type = Int;
        using pointer = void;
        using reference = void;
        using iterator_category = random_access_iterator_tag;
        Int val;
        Int operator*() {
            return val;
        }
        operator Int &() {
            return val;
        }
        operator const Int &() const {
            return val;
        }
        Int operator[](make_signed_t<Int> x) {
            return val + x;
        }
    };
    iterator begin() const {
        return iterator{first};
    }
    iterator end() const {
        return iterator{last};
    }
};

template<class Float, class Int = uint32_t>
struct frange {
    using value_type = Float;
    Float first, last;
    Int n;
    frange(Float last): first(0), last(last), n(inf) {}
    frange(Float first, Float last, Int n = inf): first(first), last(last), n(n) {}
    struct iterator: public range<Int>::iterator {
        const frange *r;
        iterator(const frange *r, Int pos): range<Int>::iterator{pos}, r(r) {}
        Float operator*() {
            return r->first + (r->last - r->first) / r->n * range<Int>::iterator::val;
        }
    };
    iterator begin() const {
        return iterator(this, 0);
    }
    iterator end() const {
        return iterator(this, n);
    }
};

template<class F, class T1, class T2, size_t... i>
inline typename enable_if<tuple_size<T1>::value == tuple_size<T2>::value, void>::type
elementwise_apply(F f, T1 &x, const T2 &y, index_sequence<i...>) {
    (f(get<i>(x), get<i>(y)), ...);
}

template<class F, class T1, class T2, size_t... i>
inline typename enable_if<is_tuple_like<T1>::value && !is_tuple_like<T2>::value, void>::type
elementwise_apply(F f, T1 &x, const T2 &y, index_sequence<i...>) {
    (f(get<i>(x), y), ...);
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type &operator+=(T1 &x, const T2 &y) {
    elementwise_apply(lambda(x += y, auto &x, auto &y), x, y, make_index_sequence<tuple_size<T1>::value>{});
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type operator+(T1 x, const T2 &y) {
    x += y;
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type &operator-=(T1 &x, const T2 &y) {
    elementwise_apply(lambda(x -= y, auto &x, auto &y), x, y, make_index_sequence<tuple_size<T1>::value>{});
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type operator-(T1 x, const T2 &y) {
    x -= y;
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type &operator*=(T1 &x, const T2 &y) {
    elementwise_apply(lambda(x *= y, auto &x, auto &y), x, y, make_index_sequence<tuple_size<T1>::value>{});
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type operator*(T1 x, const T2 &y) {
    x *= y;
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type &operator/=(T1 &x, const T2 &y) {
    elementwise_apply(lambda(x /= y, auto &x, auto &y), x, y, make_index_sequence<tuple_size<T1>::value>{});
    return x;
}

template<class T1, class T2>
inline typename enable_if<is_tuple_like<T1>::value, T1>::type operator/(T1 x, const T2 &y) {
    x /= y;
    return x;
}

template<class T, make_unsigned_t<T> mod, class U>
ostream &operator<<(ostream &out, ModInt<T, mod, U> v) {
    return out << v.x;
}

template<class T, make_unsigned_t<T> mod, class U>
istream &operator>>(istream &in, ModInt<T, mod, U> &v) {
    return in >> v.x;
}

namespace geometry {

template<class T>
bool eq(T a, T b) {
    if constexpr (is_floating_point<T>()) {
        return fabs(a - b) < EPS;
    } else {
        return a == b;
    }
}

template<class T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0): x(x), y(y) {}
    template<class U>
    inline operator Point<U>() const {
        return Point<U>(x, y);
    }
    inline Point &operator+=(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline Point &operator-=(const Point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline Point operator+(const Point &other) const {
        Point tmp = *this;
        tmp += other;
        return tmp;
    }
    inline Point operator-(const Point &other) const {
        Point tmp = *this;
        tmp -= other;
        return tmp;
    }
    inline T sqrlen() const {
        return x * x + y * y;
    }
    inline T operator*(const Point &other) const {
        return x * other.x + y * other.y;
    }
    inline T operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }
    inline Point operator-() const {
        return Point(-x, -y);
    }
    inline Point &operator*=(T c) {
        x *= c;
        y *= c;
        return *this;
    }
    inline Point &operator/=(T c) {
        x /= c;
        y /= c;
        return *this;
    }
    inline Point operator*(T c) const {
        Point tmp = *this;
        tmp *= c;
        return tmp;
    }
    inline Point operator/(T c) const {
        Point tmp = *this;
        tmp /= c;
        return tmp;
    }
    bool operator==(const Point &other) const {
        return eq(x, other.x) && eq(y, other.y);
    }
    bool operator!=(const Point &other) const {
        return !eq(x, other.x) || !eq(y, other.y);
    }
};

template<class T>
T sqrdist(const Point<T> &a, const Point<T> &b) {
    return (a - b).sqrlen();
}

template<class T1, class T2>
double dist(const T1 &a, const T2 &b) {
    return sqrt(sqrdist(a, b));
}

template<class T>
ostream &operator<<(ostream &out, const Point<T> &p) {
    return out << p.x << " " << p.y;
}

template<class T>
istream &operator>>(istream &in, Point<T> &p) {
    return in >> p.x >> p.y;
}

template<class T>
struct Line {
    union {
        struct {
            T a, b;
        };
        Point<T> normal;
    };
    T c;
    Line(T a = 1, T b = 0, T c = 0): a(a), b(b), c(c) {}
    Line(const Point<T> &p1, const Point<T> &p2): a(p2.y - p1.y), b(p1.x - p2.x), c(-(p1 * normal)) {}
    bool operator==(const Line &other) const {
        return eq(c * sqrt(other.normal.sqrlen()), other.c * sqrt(normal.sqrlen()));
    }
    bool operator!=(const Line &other) const {
        return !eq(c * sqrt(other.normal.sqrlen()), other.c * sqrt(normal.sqrlen()));
    }
};

template<class T>
double dist(const Line<T> &l, const Point<T> &p) {
    return fabs((double) (l.normal * p + l.c) / sqrt(l.normal.sqrlen()));
}

template<class T>
T dist_denomalized(const Line<T> &l, const Point<T> &p) {
    return (l.normal * p + l.c);
}

template<class T>
ostream &operator<<(ostream &out, const Line<T> &l) {
    return out << l.a << " " << l.b << " " << l.c;
}

template<class T>
istream &operator>>(istream &in, Line<T> &l) {
    return in >> l.a >> l.b >> l.c;
}

template<class T>
vector<Point<double>> intersect(const Line<T> &l1, const Line<T> &l2) {
    if (eq(l1.normal ^ l2.normal, (T) 0)) {
        if (l1 == l2) {
            return vector<Point<double>>(2);
        }
        return {};
    }
    if (eq(l2.a, (T) 0)) {
        return intersect(l2, l1);
    }
    if (eq(l1.a, (T) 0)) {
        double y = (double) -l1.c / l1.b;
        double x = (double) (-l2.b * y - l2.c) / l2.a;
        return {Point(x, y)};
    } else {
        double nb = l2.b - (double) l1.b * l2.a / l1.a;
        double nc = l2.c - (double) l1.c * l2.a / l1.a;
        double y = -nc / nb;
        double x = (double) (-l2.b * y - l2.c) / l2.a;
        return {Point(x, y)};
    }
}

template<class T>
struct Circle {
    Point<T> c;
    T r;
    bool operator==(const Circle &other) const {
        return c == other.c && eq(r, other.r);
    }
    bool operator!=(const Circle &other) const {
        return c != other.c || !eq(r, other.r);
    }
};

template<class T>
vector<Point<double>> intersect(const Circle<T> &c, const Line<T> &l) {
    double d = dist(l, c.c);
    if (d > c.r) {
        return {};
    } else {
        Point<double> dn = l.normal;
        if (dist_denomalized(l, c.c) > 0)
            dn = -dn;
        dn /= sqrt(dn.sqrlen());
        dn *= d;
        Point<double> p = c.c;
        p += dn;
        dn = l.normal;
        swap(dn.x, dn.y);
        dn.x = -dn.x;
        dn /= sqrt(dn.sqrlen());
        dn *= sqrt(c.r * c.r - d * d);
        if (p + dn == p - dn) {
            return {p + dn};
        } else {
            return {p + dn, p - dn};
        }
    }
}

template<class T>
vector<Point<double>> intersect(Circle<T> c1, Circle<T> c2) {
    if (c1 == c2) {
        return vector<Point<double>>(3);
    }
    c2.c -= c1.c;
    auto ans = intersect(c2, Line<T>(-2 * c2.c.x, -2 * c2.c.y,
        c2.c.x * c2.c.x + c2.c.y * c2.c.y + c1.r * c1.r - c2.r * c2.r));
    for (auto &p : ans)
        p += c1.c;
    return ans;
}

template<class T>
ostream &operator<<(ostream &out, const Circle<T> &c) {
    return out << c.c << " " << c.r;
}

template<class T>
istream &operator>>(istream &in, Circle<T> &c) {
    return in >> c.c >> c.r;
}

template<class T>
bool is_inside(const Point<T> &p, const vector<Point<T>> &polygon) {
    double sum = 0;
    for (int i = 0; i < (int) polygon.size(); ++i) {
        auto a = polygon[i] - p;
        auto b = polygon[(i + 1 == (int) polygon.size()) ? 0 : i + 1] - p;
        if (a * b <= 0 && eq(a ^ b, (T) 0)) {
            return 1;
        }
        sum += atan2(a ^ b, a * b);
    }
    return fabs(sum) > 1;
}

template<class T>
T sqr2(const vector<Point<T>> &polygon) {
    T sum = 0;
    for (int i = 0; i < (int) polygon.size(); ++i) {
        sum += polygon[i] ^ polygon[(i + 1 == (int) polygon.size()) ? 0 : i + 1];
    }
    if (sum < 0)
        sum = -sum;
    return sum;
}

}; // geometry

template<class T>
void debug(const T &x) {
    cout << x << endl;
}

template<class T, class... Args>
void debug(const T &x, const Args & ...args) {
    cout << x << " ";
    debug(args...);
}

template<class T>
void debugs(const T &x) {
    cout << x << " ";
}

template<class T, class... Args>
void debugs(const T &x, const Args & ...args) {
    cout << x << " ";
    debugs(args...);
}

#define named(x) #x, "=", x

// #define NODEBUG
#if defined NODEBUG || !defined LOCAL
#define debug(...)
#define debugs(...)
#endif

// ---SOLUTION--- //

// using namespace segtree;
// using namespace geometry;

ModInt<> dp[512][501] = {};
ModInt<> c[512][501] = {};

void run() {
    int n, x;
    cin >> n >> x;
    dp[0][0] = 1;
    c[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            debugs(c[i][j]);
        }
        debug("");
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i][j] = power(ModInt<>(j), i) - power(ModInt<>(j - 1), i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            for (int k = i; k <= n; ++k) {
                if (j + k - 1 >= k)
                    dp[k][j + k - 1] += dp[i][j] * power(ModInt<>(k - 1), k - i) * c[k][i];
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            debugs(dp[i][j]);
        }
        debug("");
    }
    cout << accumulate(dp[n] + 1, dp[n] + x + 1, ModInt<>(0)) << "\n";
}
