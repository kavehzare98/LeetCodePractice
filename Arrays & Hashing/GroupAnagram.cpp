#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        sort(strs.begin(), strs.end());

        // DEBUG
        cout << "After sorting: ";
        for (auto str : strs)
        {
            cout << str << " ";
        }
        cout << endl;
        // END DEBUG!


        int A_ind = 0;
        string current_string = strs[A_ind];
        answer.push_back({current_string});

        cout << "Current String: " << current_string << endl;

        for (int i = 1; i < strs.size(); i++)
        {
            bool isAnagram = true;

            if (strs[i].size() != current_string.size())
            {
                current_string = strs[i];
                answer.push_back({current_string});
                A_ind += 1;
                isAnagram = false;
            }
            else 
            {
                string old_str = current_string;
                string new_str = strs[i];

                sort(old_str.begin(), old_str.end());
                sort(new_str.begin(), new_str.end());

                for (int j = 0; j < new_str.size(); j++)
                {
                    if (old_str[j] != new_str[j])
                    {
                        current_string = strs[i];
                        answer.push_back({current_string});
                        A_ind += 1;
                        isAnagram = false;
                        break;
                    }
                }
                
                if (isAnagram)
                {
                    answer[A_ind].push_back(strs[i]);
                }

            }
            
        }

        return answer;
    }
};


int main() 
{
    Solution solution;

    vector<string> vect = {"cat", "tac", "hat"};

    vector<vector<string>> answer = solution.groupAnagrams(vect);

//    for (int r = 0; r < answer.size(); r++)
//    {
//        for (int c = 0; c < answer[r].size(); c++)
//        {
//            cout << answer[r][c] << " ";
//        }
//        cout << endl;
//    }

    return EXIT_SUCCESS;
}
