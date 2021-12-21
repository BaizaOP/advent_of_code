#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int distinct(string str) {
    switch(str.size()) {
        case 2: case 4: case 3: case 7:  //for numbers 1 (uses 2 segments), 4 (uses 4), 7 (uses 3), and 8 (uses all 7) respectively
            return 1;
            break;
        default:
            return 0;
    }
}

int main() {
    ifstream fin("file.in");
    string _, a, b, c, d;
    char ch;
    int count = 0;
//               0    1    2    3    4    5    6    7    8    9
    while(fin >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> ch >> a >> b >> c >> d) {
        count += distinct(a);
        count += distinct(b);
        count += distinct(c);
        count += distinct(d);
    }
    cout << count << endl;
    return 0;
}

