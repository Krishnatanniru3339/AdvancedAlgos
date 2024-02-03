#include <iostream>
#include <vector>

using namespace std;
    string long_substring(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    int longest = 0;  
    string longest_string; 

   
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                    longest_string = s1.substr(i - longest, longest);
                }
            }
        }
    }

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return longest_string;
}

int main() {
    
    string string1;
    string string2;
	cout<<"Enter String 1";
    cin>>string1;
    cout<<"Enter String 2";
    cin>>string2;

    string longest_common_substring = long_substring(string1, string2);

    cout << "The longest common substring for given strings is: " << longest_common_substring << std::endl;

    return 0;
}
