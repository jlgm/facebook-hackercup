/*
accepted solution
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

int h, s;
string sp[13];
double dp[1111];

bool hasZ(string a) { return a.find("+")!=string::npos || a.find("-")!=string::npos; }

void build(int x, int y) {
    ms(dp,0);
    dp[0] = 1;
    fr(i,0,x) {
        for (int j = 1110; j >= 0; j--) {
            dp[j] = 0.0;
            fr(k,1,y+1) {
                if (j - k >= 0) dp[j] += (dp[j-k] / (double)y);
            }
        }
    }
}

double solve(string ss) {
    int x, y, z = 0;
    if (hasZ(ss)) sscanf(ss.c_str(), "%dd%d%d", &x, &y, &z);
    else sscanf(ss.c_str(), "%dd%d", &x, &y); //parsing

    build(x,y);
    double ret = 0.0;

    for(int i = x; i <= x*y; i++) {
        if (i >= (h-z)) ret += dp[i];
    }

    return ret;
}

int main() {

    int t; scanf("%d", &t); fr(caso, 1, t+1) {

        scanf("%d%d", &h, &s); fr(i,0,s) cin >> sp[i];

        double ans = 0.0;
        fr(i,0,s) ans = max(ans, solve(sp[i]));

        printf("Case #%d: %.6lf\n", caso, ans);
    }

    return 0;
}
