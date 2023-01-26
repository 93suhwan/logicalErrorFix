#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define CHECK(...)
#endif

namespace {

const double eps = 1e-8;

template<typename T> inline int cmpT(T x) { return x < 0 ? -1 : x > 0; }
template<> inline int cmpT(float x) { return x < -eps ? -1 : x > eps; }
template<> inline int cmpT(double x) { return x < -eps ? -1 : x > eps; }
template<> inline int cmpT(long double x) { return x < -eps ? -1 : x > eps; }

template<typename T>
struct VecT {
  T x = 0;
  T y = 0;

  static_assert(std::is_arithmetic<T>::value, "T should be an arithmetic type.");

  VecT() {}
  VecT(T x, T y) : x(x), y(y) {}
  ~VecT() {}

  T length_sqr() const { return x * x + y * y; }
  VecT rotate90() const { return VecT(-y, x); }

  double length() const { return hypot(x, y); }
  VecT<std::common_type_t<T, double>> rotate(double angle) const {
    const double c = cos(angle), s = sin(angle);
    return VecT<std::common_type_t<T, double>>(x * c - y * s, x * s + y * c);
  }
  template<typename U> VecT<U> convert() const { return VecT<U>(x, y); }
};

// +
template<typename T> inline VecT<T>& operator += (VecT<T>& lhs, const VecT<T>& rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}
template<typename T> inline VecT<T> operator + (VecT<T> lhs, const VecT<T>& rhs) {
  return lhs += rhs;
}

// -
template<typename T> inline VecT<T>& operator -= (VecT<T>& lhs, const VecT<T>& rhs) {
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}
template<typename T> inline VecT<T> operator - (VecT<T> lhs, const VecT<T>& rhs) {
  return lhs -= rhs;
}

// *
template<typename T, typename U> inline VecT<T>& operator *= (VecT<T>& v, U t) {
  v.x *= t;
  v.y *= t;
  return v;
}
template<typename T, typename U> inline VecT<std::common_type_t<T, U>> operator * (const VecT<T>& v, U t) {
  auto ret = v.template convert<std::common_type_t<T, U>>();
  return ret *= t;
}
template<typename T, typename U> inline VecT<std::common_type_t<T, U>> operator * (U t, const VecT<T>& v) {
  return v * t;
}

// /
template<typename T, typename U> inline VecT<T>& operator /= (VecT<T>& v, U t) {
  v.x /= t;
  v.y /= t;
  return v;
}
template<typename T, typename U> inline VecT<std::common_type_t<T, U>> operator / (const VecT<T>& v, U t) {
  auto ret = v.template convert<std::common_type_t<T, U>>();
  return ret /= t;
}

// <
template<typename T> inline bool operator < (const VecT<T>& lhs, const VecT<T>& rhs) {
  if (cmpT(lhs.x - rhs.x) == 0) return cmpT(lhs.y - rhs.y) < 0;
  return cmpT(lhs.x - rhs.x) < 0;
}
template<typename T> inline bool operator > (const VecT<T>& lhs, const VecT<T>& rhs) { return rhs < lhs; }
template<typename T> inline bool operator == (const VecT<T>& lhs, const VecT<T>& rhs) {
  return cmpT(lhs.x - rhs.x) == 0 && cmpT(lhs.y - rhs.y) == 0;
}
template<typename T> inline bool operator != (const VecT<T>& lhs, const VecT<T>& rhs) { return !(lhs == rhs); }

template<typename T>
std::string to_string(const VecT<T>& v) {
  return std::string("VecT{x=") + std::to_string(v.x) + ",y=" + std::to_string(v.y) + "}";
}

template<typename T> T det(const VecT<T>& a, const VecT<T>& b) { return a.x * b.y - a.y * b.x; }
template<typename T> T dot(const VecT<T>& a, const VecT<T>& b) { return a.x * b.x + a.y * b.y; }

template<typename T> using PointT = VecT<T>;
template<typename T> using PolygonT = std::vector<PointT<T>>;

template<typename T>
bool polar_cmp(const VecT<T>& a,const VecT<T>& b) {
  if (cmpT(a.y) * cmpT(b.y) <= 0) {
    if (cmpT(a.y) > 0 || cmpT(b.y) > 0) return cmpT(a.y - b.y) < 0;
    if (cmpT(a.y) == 0 && cmpT(b.y) == 0) return cmpT(a.x - b.x) < 0;
  }
  return cmpT(det(a,b)) > 0;
}

template<typename T>
PointT<std::common_type_t<T, double>> intersection_line_line(
    const PointT<T>& p, const PointT<T>& pp, const PointT<T>& q, const PointT<T>& qq) {
  using R = std::common_type_t<T, double>;
  const VecT<T> u = p - q, v = pp - p, w = qq - q;
  const R ratio = det(w, u) / static_cast<R>(det(v, w));
  return PointT<R>(p.x + v.x * ratio, p.y + v.y * ratio);
}

template<typename T>
PointT<std::common_type_t<T, double>> projection_point_line(const PointT<T>& p, const PointT<T>& a, const PointT<T>& b) {
  using R = std::common_type_t<T, double>;
  const VecT<T> v = b - a;
  const R ratio = dot(v, p - a) / static_cast<R>(dot(v, v));
  return PointT<R>(a.x + v.x * ratio, a.y + v.y * ratio);
}

template<typename T>
double distance_point_line(const PointT<T>& p, const PointT<T>& a, const PointT<T>& b) {
  const VecT<T> v1 = b - a, v2 = p - a;
  return std::abs(det(v1, v2)) / v1.length();
}

template<typename T>
double distance_point_segment(const PointT<T>& p, const PointT<T>& a, const PointT<T>& b) {
  if (a == b) return (p - a).length();
  const VecT<T> v1 = b - a, v2 = p - a, v3 = p - b;
  if (cmpT(dot(v1, v2)) < 0) return v2.length();
  else if (cmpT(dot(v1, v3)) > 0) return v3.length();
  else return std::abs(det(v1, v2)) / v1.length();
}

template<typename T>
bool has_proper_intersection_segment_segment(
    const PointT<T>& a1, const PointT<T>& a2, const PointT<T>& b1, const PointT<T>& b2) {
  T c1 = det(a2 - a1, b1 - a1),
    c2 = det(a2 - a1, b2 - a1),
    c3 = det(b2 - b1, a1 - b1),
    c4 = det(b2 - b1, a2 - b1);
  return cmpT(c1) * cmpT(c2) < 0 && cmpT(c3) * cmpT(c4) < 0;
}

// End point counts.
template<typename T>
bool on_point_segment(const PointT<T>& p, const PointT<T>& a1, const PointT<T>& a2) {
  return cmpT(det(a1 - p, a2 - p)) == 0 && cmpT(dot(a1 - p, a2 - p)) <= 0;
}

// End point counts.
template<typename T>
bool has_intersection_segment_segment(
    const PointT<T>& a1, const PointT<T>& a2, const PointT<T>& b1, const PointT<T>& b2) {
  if (has_proper_intersection_segment_segment(a1, a2, b1, b2)) return true;
  return
    on_point_segment(a1, b1, b2) || on_point_segment(a2, b1, b2) ||
    on_point_segment(b1, a1, a2) || on_point_segment(b2, a1, a2);
}

template<typename T>
bool in_point_polygon(const PointT<T>& o, const PolygonT<T>& poly, bool flag) {
  // flag == true means boundary counts as inner side.
  int t = 0;
  PointT<T> a, b;
  const int n = poly.size();
  for (int i = 0; i < n; ++ i) if (on_point_segment(o, poly[i], poly[(i + 1) % n])) return flag;
  for (int i = 0; i < n; ++ i) {
    a = poly[i];
    b = poly[(i + 1) % n];
    if (cmpT(a.y - b.y) > 0) std::swap(a, b);
    if (cmpT(det(a - o, b - o)) < 0 && cmpT(a.y - o.y) < 0 && cmpT(o.y - b.y) <= 0) ++t;
  }
  return t & 1;
}

using Vector = VecT<double>;
using Point = Vector;
using Polygon = std::vector<Point>;

inline int dcmp(double x) { return cmpT(x); }

struct Solver {
  int n;
  Point start;
  Point outer;
  std::vector<Point> points;

  void find_outer() {
    if (n == 3) {
      outer = points.back();
      return;
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        int count = 0;
        for (int k = 0; k < 4; ++k) {
          if (dcmp(det(points[j] - points[i], points[k] - points[i])) == 0) {
            ++count;
          }
        }
        if (count >= 3) {
          for (int k = 0; k < n; ++k) {
            if (dcmp(det(points[j] - points[i], points[k] - points[i])) != 0) {
              outer = points[k];
              points.erase(points.begin() + k);
              return;
            }
          }
        }
      }
    }
    assert(false);
  }

  double solve() {
    std::sort(points.begin(), points.end());
    find_outer();
    points.erase(std::remove(points.begin(), points.end(), start), points.end());
    if (start == outer) {
      return std::min((outer - points[0]).length() + (points[0] - points.back()).length(),
                      (outer - points.back()).length() + (points[0] - points.back()).length());

    }
    double result = 1e18;

    for (int iter = 0; iter < 2; ++iter) {
      std::reverse(points.begin(), points.end());
      result = std::min(result, (start - points[0]).length() + (points[0] - points.back()).length() + (points.back() - outer).length());
      result = std::min(result, (start - outer).length() + (outer - points[0]).length() + (points[0] - points.back()).length());
      for (int i = 0; i + 1 < points.size(); ++i) {
          double val = std::min((start - points[i]).length() + (points[i] - points[0]).length() + (points[0] - outer).length(),
                                (start - points[0]).length() + (points[0] - points[i]).length() + (points[i] - outer).length());
          double X = (outer - points[i + 1]).length();
          double Y = (outer - points.back()).length();
          double Z = (points[i + 1] - points.back()).length();
          val += (X + Y + Z) - std::max({X, Y, Z});
          result = std::min(result, val);
      }
    }
    return result;
  }

  void solve(int ca, std::istream& reader) {
    int k;
    reader >> n >> k;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
      reader >> points[i].x >> points[i].y;
    }
    start = points[k - 1];
    printf("%.13f\n", solve());
  }
};

}  // namespace

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

