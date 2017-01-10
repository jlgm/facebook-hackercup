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

bool cmp(int a, int b) { return a > b; }

int n, a[200];

int main() {

    int t; scanf("%d", &t); fr(caso,1,t+1) {
        scanf("%d", &n); fr(i,0,n) scanf("%d", &a[i]);

        sort(a,a+n,cmp);
        int st = 0, end = n-1, ans = 0;

        while(st < end) {
            int up = a[st];
            int bot = a[end];

            int amt = ceil((double)50/(double)up);

            ans += ((up*(amt)>=50) && ((amt)<=(abs(st-end)+1)));

            st++; end-=(amt-1);
        }

        if (st == end) ans += (a[st]>=50);

        printf("Case #%d: %d\n", caso, ans);
    }

    return 0;
}
