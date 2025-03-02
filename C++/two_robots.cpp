#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <climits>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoRobots' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. 2D_INTEGER_ARRAY queries
 */

int twoRobots(int m, vector<vector<int>>& queries)
{
    int n = queries.size();
    if (n == 0) return 0;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, INT_MAX)));

    for (int j = 1; j <= m; ++j)
        dp[1][j][0] = abs(queries[0][1] - queries[0][0]);

    for (int i = 2; i <= n; ++i)
    {
        int a_i = queries[i - 1][0];
        int b_i = queries[i - 1][1];

        for (int r1 = 0; r1 <= m; ++r1)
        {
            for (int r2 = 0; r2 <= m; ++r2)
            {
                if (dp[i - 1][r1][r2] == INT_MAX) continue;
                
                dp[i][a_i][b_i] = min(dp[i][a_i][b_i], dp[i - 1][r1][r2] + abs(r1 - a_i) + abs(r2 - b_i));
                dp[i][b_i][a_i] = min(dp[i][b_i][a_i], dp[i - 1][r1][r2] + abs(r1 - b_i) + abs(r2 - a_i));
            }
        }
    }

    int min_distance = INT_MAX;
    for (int r1 = 0; r1 <= m; ++r1)
        for (int r2 = 0; r2 <= m; ++r2)
            min_distance = min(min_distance, dp[n][r1][r2]);

    return min_distance;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    while (t--) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int m = stoi(first_multiple_input[0]);
        int n = stoi(first_multiple_input[1]);

        vector<vector<int>> queries(n);

        for (int i = 0; i < n; i++) {
            queries[i].resize(2);

            string queries_row_temp_temp;
            getline(cin, queries_row_temp_temp);

            vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int queries_row_item = stoi(queries_row_temp[j]);

                queries[i][j] = queries_row_item;
            }
        }

        int result = twoRobots(m, queries);

        fout << result << "\n";
    }

    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),
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