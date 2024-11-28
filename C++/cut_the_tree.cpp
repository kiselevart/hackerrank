#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int dfs(vector<int>& data, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& sums, int curr) {
    visited[curr] = true;

   sums[curr] += data[curr];
    for (const auto& nbr : adj[curr]) {
        if (!visited[nbr]) {
            sums[curr] += dfs(data, adj, visited, sums, nbr);
        }
    }

    return sums[curr];
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int total = accumulate(data.begin(), data.end(), 0);
    int n = data.size();
    vector<vector<int>> adj(n);

    int u, v;
    for (const auto& edge : edges) {
        u = edge[0] - 1;
        v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n);
    vector<int> sums(n);

    dfs(data, adj, visited, sums, 0);

    int diff;
    int min = total;
    for (int sum : sums) {
        diff = abs(total - 2*sum);
        if (diff < min)
            min = diff;
    }

    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(),
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
