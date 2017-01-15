#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back

typedef long long ll;
typedef int TYPE;

struct pt {
    TYPE x, y;
    pt(TYPE x = 0, TYPE y = 0) : x(x), y(y) { }
};

struct sq {
    TYPE x, y, d;
    sq(TYPE x = 0, TYPE y = 0, TYPE d = 0) : x(x), y(y), d(d) { }
};

int n, r;
pt pts[55];

int pts_sq(sq q) {
    int ret = 0;
    fr(i,0,n) {
        int x = pts[i].x, y = pts[i].y;
        if (q.x <= x && q.y <= y && q.x+r >= x && q.y+r >= y) ret+=1;
    }
    return ret;
}

int pts_sqs(sq q, sq p) {
    int ret = 0;
    fr(i,0,n) {
        int x = pts[i].x, y = pts[i].y;
        if (q.x <= x && q.y <= y && q.x+r >= x && q.y+r >= y &&
                p.x <= x && p.y <= y && p.x+r >= x && p.y+r >= y) ret++;
    }
    return ret;
}

int main() {

    int t; scanf("%d", &t); fr(caso, 1, t+1) {

        scanf("%d%d", &n, &r);
        fr(i,0,n) {
            int x, y;
            scanf("%d%d", &x, &y);
            pts[i] = pt(x,y);
        }

        int ans = 0;

        fr(i,0,n) fr(j,0,n) {
            sq q = sq(min(pts[i].x, pts[j].x), min(pts[i].y, pts[j].y));
            fr(k,0,n) fr(l,0,n) {
                sq p = sq(min(pts[l].x, pts[k].x), min(pts[l].y, pts[k].y));
                ans = max(ans, pts_sq(p) + pts_sq(q) - pts_sqs(q,p));
            }
        }

        printf("Case #%d: %d\n", caso, ans);
    }

    return 0;
}
