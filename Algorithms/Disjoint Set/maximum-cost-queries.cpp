// https://www.hackerrank.com/challenges/maximum-cost-queries/submissions/code/257511630

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an intEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_intEGER_ARRAY tree
 *  2. 2D_intEGER_ARRAY queries
 */
 
#define M 200000
#define int int64_t
 
class DJ {
public:
    DJ(int N) : N(N) {
        init();
    }    
    int parent[M], rank[M];
    int count[M];

    void init() {
        for (int i=0; i<N; i++) {
            parent[i] = i;
            rank[i] = 0;
            count[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) {
            parent[u] = v;
            count[v] += count[u];
        }
        else {
            parent[v] = u;
            count[u] += count[v];
        }
    }
    
    int getCount(int i) {
        return count[i];
    }
private:
    int N;
};

vector<int> solve(vector<vector<int>> t, vector<vector<int>> q) {
    int n = t.size();
    int m = q.size();
    
    unordered_map<int, int> val;
    
    sort(t.begin(), t.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    DJ dj(n + 2);
    
    for (int i = 0; i < n; i++) {
        int count1 = dj.getCount(dj.find(t[i][0]));
        int count2 = dj.getCount(dj.find(t[i][1]));
        
        val[t[i][2]] += (count1 - 1) + (count2 - 1) + 1 + (count1 - 1) * (count2 - 1);
        dj.join(t[i][0], t[i][1]);
        
    }
    
    vector<int> key;
    for (auto e : val) {
        key.push_back(e.first);
    }

    sort(key.begin(), key.end());
    
    vector<int> pref(key.size(), 0);
    pref[0] = val[key[0]];
    for (int i = 1; i < pref.size(); i++) {
        pref[i] = pref[i - 1] + val[key[i]];
    }
    
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
        int l = q[i][0];
        int r = q[i][1];
        
        int b = lower_bound(key.begin(), key.end(), l) - key.begin();
        int e = upper_bound(key.begin(), key.end(), r) - key.begin() - 1;
        if (b > e) {
            continue;
        } else {

            if (b == 0) {
                ans[i] = pref[e];
            } else {
                ans[i] = pref[e] - pref[b - 1];
            }
        }
        
    }
    
    return ans;
    
}

int32_t main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> tree(n - 1);

    for (int i = 0; i < n - 1; i++) {
        tree[i].resize(3);

        string tree_row_temp_temp;
        getline(cin, tree_row_temp_temp);

        vector<string> tree_row_temp = split(rtrim(tree_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int tree_row_item = stoi(tree_row_temp[j]);

            tree[i][j] = tree_row_item;
        }
    }

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = solve(tree, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int32_t, int32_t>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int32_t, int32_t>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
