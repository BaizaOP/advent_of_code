#include <bits/stdc++.h>
using namespace std;

// my competitive programming boilerplate... for some reason
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
typedef vector<vvi> vvvi; // 3d eggsdee

//protos
vi parse_bingo_calls(string calls);
vvvi parse_tables(ifstream& is);
void show_bingo_table (vvi bingo_table);
void print_tables (vvvi bingo_tables);
bool check_rows (vvi bingo_table);
bool check_cols (vvi bingo_table);
void insert_bingo (vvi& table, int call);
long long sum_all_unmarked(vvi bingo);
void remove_table(vvvi& bingo, int index);

int main() {
    /* ifstream fin ("sample.in"); */
    ifstream fin ("file.in");
    string calls; getline(fin, calls);
    vi nums = parse_bingo_calls(calls);

    vvvi bingo = parse_tables(fin);
    vvvi initial_bingo = bingo; 
    /* print_tables(bingo); */
    int num_counter = 0;
    long long latest_ans = 0;
    while(bingo.size() > 0) { 
        int sz = bingo.size();
        for(int j = sz - 1; j >= 0; j--) {
            insert_bingo (bingo[j], nums[num_counter]);

            if(check_rows(bingo[j]) || check_cols(bingo[j])) {
                latest_ans = sum_all_unmarked(bingo[j]) * nums[num_counter];
                remove_table(bingo, j);
            }
        }
        num_counter++;
    }
    cout << latest_ans << endl;

    return 0;
}

vi parse_bingo_calls(string calls) {
    calls.pb(','); 
    vi nums; 
    string num = "";
    for(int i = 0; i < calls.size(); i++) {
        if(calls[i] ==  ',') {
            nums.pb(stoi(num));
            num = "";
        } else {
            num.pb(calls[i]);
        }
    } 
    return nums;
}

vvvi parse_tables(ifstream& is) {
    vvvi bingo_tables = {};
    vvi bingo_table = {};
    vi row = {};
    int n;
    int counter = 0;
    while (is >> n) {
        row.push_back(n);
        counter++;
        if(counter % 5 == 0) {
            bingo_table.pb(row);
            row = {};
            if(counter == 25) {
                bingo_tables.pb(bingo_table);
                bingo_table = {};
                counter = 0; 
            }
        }
    }
    return bingo_tables;
}
void show_bingo_table (vvi bingo_table) {
    for(vi b : bingo_table) {
        for(int i : b) {
            cout << i << ' ';
        }
        cout << endl;
    }
}

void print_tables (vvvi bingo_tables) {
    for(vvi a : bingo_tables) {
        cout << "---\n";
        show_bingo_table(a);
        cout << "---\n";
    }
}

bool check_rows (vvi bingo_table) {
    for(int i = 0; i < 5; i++) {
        int sum = 0;
        for(int j = 0; j < 5; j++) {
            sum += bingo_table[i][j];
        }
        /* if(i == 0) cout << sum << endl; */
        if(sum == -5)
            return true;
    }
    return false;
}

bool check_cols (vvi bingo_table) {
    for(int i = 0; i < 5; i++) {
        int sum = 0;
        for(int j = 0; j < 5; j++) {
            sum += bingo_table[j][i];
        }
        /* if(i == 0) cout << sum << endl; */
        if(sum == -5)
            return true;
    }
    return false;
}

void insert_bingo (vvi& table, int call) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(table[i][j] == call) {
                table[i][j] = -1;
            }
        }
    }
}

long long sum_all_unmarked(vvi bingo){
    long long sum = 0;
    for(int i = 0; i < bingo.size(); i++) {
        for(int j = 0; j < bingo[0].size(); j++) {
            if(bingo[i][j] != -1) sum += bingo[i][j];
        }
    }
    return sum;
}

void remove_table(vvvi& bingo, int index) {
    bingo.erase(bingo.begin() + index);
}
