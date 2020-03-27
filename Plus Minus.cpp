#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<float> plusMinus(vector<int> arr) {
    int s = arr.size();
    vector<float> res;
    res.resize(3);
    for (int i=0; i<s; i++)
        if (arr[i] > 0)
            res[0] += 1;
        else if (arr[i] < 0)
            res[1] += 1;
        else
            res[2] += 1;
    for (int i=0; i<3; i++)
        res[i] /= s;
    return res;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<float> output = plusMinus(arr);
    for (int i=0; i<3; i++)
        cout << output[i] << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
