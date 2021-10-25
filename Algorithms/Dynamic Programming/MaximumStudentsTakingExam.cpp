// https://leetcode.com/problems/maximum-students-taking-exam/

// dp with bitset

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        
        // dp[i][j]: number of max sastify students from row m - 1 to row i, state row i is j.
        // cout << "pow(2, n) - 1: " << pow(2, n) - 1 << endl;
        vector<vector<int>> dp(m, vector<int>(pow(2, n) - 1, 0));
        
        int max_in_row = pow(2, n) - 1; // 1 << n - 1
        
        for (int value_row = 0; value_row < max_in_row; value_row++) {
            bool validate_state = true;
            // cout << "Check val: " << value_row << endl;
            for (int i = 0; i < n; i++) {
                if (seats[m - 1][i] == '.') {
                    continue;
                }
                if (value_row & (1 << (n - 1 - i))) {
                    validate_state = false;
                    break;
                }
            }
            if (!validate_state) {
                continue;
            }
            
            
            // validate row   
            bool validate = true;
            int value_row_cp = value_row;
            vector<int> r1;
            for (int idx = 0; idx < n; idx++) {
                r1.push_back(value_row_cp % 2);
                value_row_cp = value_row_cp / 2;
            }
            for (int i = 0; i < n - 1; i++) {
                if (r1[i] == 1 && r1[i + 1] == 1) {
                    validate = false;
                    break;
                }
            }
            if (!validate) {
                // cout << "Not validated! row: " << ", value_row: " << value_row << endl;
                continue;
            }
            
            
            int value = 0;
            int s = value_row;
            while (s > 0) {
                value += s % 2;
                s = s / 2;
            }
            // cout << "accept: " << value_row << endl;
            dp[m - 1][value_row] = value;
            // cout << "value_row: " << value_row << ", value: " << value << endl;
            
        }
        
        for (int row = m - 2; row >= 0; row--) {
            for (int value_row = 0; value_row < max_in_row; value_row++) {
                // cal dp[row][..]
                bool validate_state = true;
                // cout << "Check val: " << value_row << endl;
                for (int i = 0; i < n; i++) {
                    if (seats[row][i] == '.') {
                        continue;
                    }
                    if (value_row & (1 << (n - 1 - i))) {
                        validate_state = false;
                        break;
                    }
                }
                if (!validate_state) {
                    continue;
                }

                int value = 0;
                int s = value_row;
                while (s > 0) {
                    value += s % 2;
                    s = s / 2;
                }
                
                // validate row   
                bool validate = true;
                int value_row_cp = value_row;
                vector<int> r1;
                for (int idx = 0; idx < n; idx++) {
                    r1.push_back(value_row_cp % 2);
                    value_row_cp = value_row_cp / 2;
                }
                for (int i = 0; i < n - 1; i++) {
                    if (r1[i] == 1 && r1[i + 1] == 1) {
                        validate = false;
                        break;
                    }
                }
                if (!validate) {
                    // cout << "Not validated! row: " << row << ", value_row: " << value_row << endl;
                    continue;
                }
                
                
                // cout << "accept: " << value_row << endl;
                dp[row][value_row] = value;
                // cout << "value_row: " << value_row << ", value: " << value << endl;
                
                int m = 0;
                for (int value_last_row = 0; value_last_row < max_in_row; value_last_row++) {
                    // if (conflict(value_last_row, value_row)) {
                    //     continue;
                    // }
                    // check conflict
                    bool conflict = false;
                    vector<int> r1;
                    vector<int> last_r1;
                    int value_last_row_cp = value_last_row;
                    int value_row_cp = value_row;
                    for (int idx = 0; idx < n; idx++) {
                        r1.push_back(value_row_cp % 2);
                        value_row_cp = value_row_cp / 2;
                    }
                    
                    for (int idx = 0; idx < n; idx++) {
                        last_r1.push_back(value_last_row_cp % 2);
                        value_last_row_cp = value_last_row_cp / 2;
                    }
                    
                    for (int idx = 0; idx < n; idx++) {
                        if (last_r1[idx] == 0) {
                            continue;
                        }
                        if (idx == 0) {
                            if (r1[idx + 1] == 1) {
                                conflict = true;
                                break;
                            }
                        } else if (idx == n - 1) {
                            if (r1[idx - 1] == 1) {
                                conflict = true;
                                break;
                            }
                        } else {
                            if (r1[idx + 1] == 1 || r1[idx - 1] == 1) {
                                conflict = true;
                                break;
                            }
                        }
                    }
                    
                    if (conflict) {
                        continue;
                    }
               
                    
                    m = max(m, dp[row + 1][value_last_row]);
                    
                    // cout << ": " << m << ", row: " << row << ", not conflict: " << value_row << " and " << value_last_row << endl;
                }
                dp[row][value_row] += m;
                // cout << "m: " << m << ", row: " << row << ", value_row: " << value_row << ", v: " << dp[row][value_row] << endl;
            }
            
        }
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < max_in_row; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        int ans = 0;
        for (int value_row = 0; value_row < max_in_row; value_row++) {
            ans = max(ans, dp[0][value_row]);
        }

        return ans;
    
        
    }
};