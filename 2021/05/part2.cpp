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

int count_intersections (vvi grid) {
    int counter = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[j][i] > 1) counter++;
        }
    }
    return counter;
}

vvi make_grid(int x, int y) {
    vvi grid;
    for(int i = 0; i < y; i++) {
        vi row;
        for(int j = 0; j < x; j++) {
            row.pb(0);
        }
        grid.pb(row);
    }
    return grid;
}

void draw_line (vvi& grid, int x1, int y1, int x2, int y2) {
    int minx = min(x1, x2);
    int maxx = max(x1, x2);
    int miny = min(y1, y2);
    int maxy = max(y1, y2);
    if(x1 == x2) {
        /* cout << "xs are equal" << endl; */
        for(int i = miny; i <= maxy; i++) {
            grid[i][x1]++;
        }
    } else if (y1 == y2) {
        /* cout << "ys are equal" << endl; */
        for(int i = minx; i <= maxx; i++) {
            grid[y1][i]++;
        }
    } else if (abs(y2 - y1) == abs(x2 - x1)) {
        int xinc = (x1 > x2 ? -1 : 1);
        int yinc = (y1 > y2 ? -1 : 1);
        for(int i = x1, j = y1, counter = 0; counter <= abs(y2 - y1); counter++, i+=xinc, j+=yinc) {
            /* printf("(%d, %d)\n", j, i); */ 
            grid[j][i]++;
        }
    }
}

int main() {
    ifstream fin("file.in");
    int x1, y1, x2, y2;
    char ch;
    vvi grid;
    grid = make_grid(1100, 1100);
    while (fin >> x1 >> ch >> y1 >> ch >> ch >> x2 >> ch >> y2) {
        draw_line(grid, x1, y1, x2, y2);
    }
    cout << count_intersections(grid) << endl;
    return 0;
}

