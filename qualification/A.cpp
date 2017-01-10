/*
Wrong answer: my angle() function returns the smallest angle between three points, which is not what I intended.
Fix: verify if X is less than 50. If it is, angle() should be added 180.
*/

#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef double TYPE;

const TYPE EPS = 1e-9, INF = 1e9;
const TYPE D = 50.0;

struct pt {
    TYPE x, y;
    pt(TYPE x = 0, TYPE y = 0) : x(x), y(y) { }
    TYPE operator||(pt p) { return x*p.x + y*p.y; }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
};

TYPE abs(pt a) { return sqrt(a||a); }
TYPE dist(pt a, pt b) { return abs(a - b); }

TYPE p, x, y;

TYPE angle(pt p0, pt p1, pt c) {
    TYPE p0c = dist(p0,c);
    TYPE p1c = dist(p1,c);
    TYPE p0p1 = dist(p0,p1);
    return acos((p1c*p1c+p0c*p0c-p0p1*p0p1)/(2*p1c*p0c));
}

int main() {

    pt p1(50,50);
    pt p2(50,100);

    int t; scanf("%d", &t); fr(caso,1,t+1) {
        cin >> p >> x >> y;
        pt p3(x,y);

        p = 360*p/100;
        TYPE q = angle(p3,p2,p1) * 180/acos(-1);

        bool ans = (q<p) && (dist(p3,p1) < D);

        printf("Case #%d: %s\n", caso, ans?"black":"white");
    }

    return 0;
}
