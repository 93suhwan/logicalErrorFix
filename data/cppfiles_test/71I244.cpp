#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 200021
#define eps 1e-9
using namespace std;

struct point{
    double x, y;
    bool operator < (point b){ return make_pair(x, y) < make_pair(b.x, b.y); }
};
vector<point> p;
struct line{ double a, b, c; };
int n, k;
int xk, yk;

line get_line(point a, point b){
    return {b.y-a.y, a.x-b.x, b.x*a.y - a.x*b.y};
}

line get_vertical(line l, point k){
    if(fabs(l.a) < eps) return (line){1, 0, -k.x};
    double a = l.b/l.a, b = -1;
    double c = -(a*k.x + n*k.y);
    return (line){a, b, c};
}

point intersect(line a, line b){
    double x = (b.c*a.b - a.c*b.b) / (a.a*b.b - b.a*a.b);
    double y = a.b ? -(a.c + a.a*x) / a.b : -(b.c + b.a*x) / b.b;
    return {x, y};
}

double cal(vector<point> p){
    double dis = 0;
    rep(i,0,(int)p.size()-2)
        dis += sqrt((p[i].x-p[i+1].x)*(p[i].x-p[i+1].x) + (p[i].y-p[i+1].y)*(p[i].y-p[i+1].y));
    return dis;
}

int main(){
    cin>>n>>k;
    p.resize(n);
    rep(i,0,n-1) scanf("%lf %lf", &p[i].x, &p[i].y);
    xk = p[k-1].x, yk = p[k-1].y;
    sort(p.begin(), p.end());
    //for(point pp : p) cout<<"("<<pp.x<<","<<pp.y<<") "; cout<<endl;

    line coline;
    point ex;
    rep(i,0,1) rep(j,i+1,2){
        line l = get_line(p[i], p[j]);
        int cnt = 0;
        point tmp;
        //cout<<"("<<l.a<<","<<l.b<<","<<l.c<<")\n";
        rep(k,0,n-1) if(fabs(p[k].x*l.a + p[k].y*l.b + l.c) > eps) cnt++, tmp = p[k];
        //cout<<i<<","<<j<<": "<<cnt<<endl;
        if(cnt <= 1) coline = l, ex = tmp;
    }
    //cout<<"ex: ("<<ex.x<<","<<ex.y<<")\n";
    p.erase(lower_bound(p.begin(), p.end(), ex));
    n--;

    vector<point> node;
    int pos = lower_bound(p.begin(), p.end(), (point){xk, yk}) - p.begin();
    node.push_back(p[pos]);
    if(pos >= 1) node.push_back(p[pos-1]);
    if(pos < n-1) node.push_back(p[pos+1]);
    //for(point pp : node) cout<<"("<<pp.x<<","<<pp.y<<") ";
    //cout<<endl;
    node.push_back(p.front()), node.push_back(p.back());

    node.push_back(ex);
    point itc = intersect(coline, get_vertical(coline, ex));
    pos = lower_bound(p.begin(), p.end(), itc) - p.begin();
    node.push_back(p[pos]);
    if(pos > 1) node.push_back(p[pos-1]);

    //for(point pp : node) cout<<"("<<pp.x<<","<<pp.y<<") ";
    //cout<<endl;

    double ans = 1e12;
    int m = node.size(), num = 1;
    rep(i,1,m-1) num *= i;
    while(num--){
        ans = min(ans, cal(node));
        next_permutation(node.begin()+1, node.end());
    }

    printf("%.10f\n", ans);
    return 0;
}