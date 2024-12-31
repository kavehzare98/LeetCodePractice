#include <iostream>
#include <stack>

using std::cout, std::endl, std::stack, std::string;

class Solution {
public:
    
    bool isOpen(char paren)
    {
       bool open = false;

       if (paren == '(')
       {
            open = true;
       }
       else if (paren == '{')
       {
            open = true;
       }
       else if (paren == '[')
       {
            open = true;
       }

       return open;
    }

    bool isMatching(char c1, char c2)
    {
        bool matching = true;
        if (c1 == '(')
        {
            if (c2 != ')')
            {
                matching = false;
            }
        }
        else if (c1 == '{')
        { 
            if (c2 != '}')
            {
                matching = false;
            }
        }
        else if (c1 == '[')
        {
            if (c2 != ']')
            {
                matching = false;
            }
        }

        return matching;
    }


    bool isValid(string s) {
        stack<char> open_chars;
        bool valid = true;

        // Edge case: Making sure there is an even number of characters.
        if (s.size() % 2 != 0)
        {
            valid = false;
        }
        else 
        {
            int i = 0;
            while (i < s.size() && valid == true)
            {
                if (isOpen(s[i]))
                {
                    open_chars.push(s[i]);
                }
                else if (!isOpen(s[i]) && open_chars.size() != 0) 
                {
                    valid = isMatching(open_chars.top(), s[i]);
                    open_chars.pop();
                }
                else
                {
                    valid = false;
                }

                i++;
            }

            if (valid && open_chars.size() != 0)
            {
                valid = false;
            }

        }
        return valid;
    }
};


int main()
{
	Solution solution;

	cout << "The following: ( is ... ";
	if (solution.isOpen('('))
	{
		cout << "OPEN" << endl;
	}
	else {
		cout << "CLOSED" << endl;
	}

       	cout << "The following: ) is ... ";
	if (solution.isOpen(')'))
	{
		cout << "OPEN" << endl;
	}
	else {
		cout << "CLOSED" << endl;
	}


        cout << "The following chars are: ( & ) are ... ";
        if (solution.isMatching('(', ')'))
            cout << "MATCHING" << endl;
        else 
            cout << "NOT MATCHING" << endl;

       cout << "The following chars are: { & ] are ... ";
        if (solution.isMatching('{', ']'))
            cout << "MATCHING" << endl;
        else 
            cout << "NOT MATCHING" << endl;


        const int SIZE = 7;
        string tests[SIZE] = {"()", "[]", "{}", "{}{", "{}()[]", "{[()]}", "{([)]}"};

        for (int i = 0; i < SIZE; i++)
        {
            cout << "TEST " << i + 1 << ": " << tests[i] << " is " << solution.isValid(tests[i]) << endl;
        }


	return EXIT_SUCCESS;
}
