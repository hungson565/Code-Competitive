// https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

#define int int64_t

/*
 * Complete the 'minimumAverage' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY customers as parameter.
 */
 
class Compare
{
public:
    bool operator() (vector<int> a, vector<int> b)
    {
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
};

int minimumAverage(vector<vector<int>> arr) {
    std::priority_queue<vector<int>, std::vector<vector<int>>, Compare> q;
    int n = arr.size();
    
    sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b [1];
    });
    
    int time = arr[0][1];
    int s = 0;
    int i = 0;

    while (!q.empty() || i < n) {
        if (!q.empty()) {
            vector<int> t = q.top();
            q.pop();
            // process t
            time += t[1];
            s += (time - t[0]);
            
            // push arr [i]
            while (i < n && arr[i][0] < time ) {
                q.push(arr[i]);
                i++;
            }
        } else {
            q.push(arr[i]);
            time = arr[i][0];
            i++;
        }
    }
    
    return s / n;
}

int32_t main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> customers(n);

    for (int i = 0; i < n; i++) {
        customers[i].resize(2);

        // string customers_row_temp_temp;
        // getline(cin, customers_row_temp_temp);

        // vector<string> customers_row_temp = split(rtrim(customers_row_temp_temp));

        // for (int j = 0; j < 2; j++) {
        //     int customers_row_item = stoi(customers_row_temp[j]);

        //     customers[i][j] = customers_row_item;
        // }
        int a, b;
        cin >> a >> b;
        customers[i][0] = a;
        customers[i][1] = b;
    }

    int result = minimumAverage(customers);

    fout << result << "\n";

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
