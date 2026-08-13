// end() is not actually the last character. It's one position after it.
<<<<<<< HEAD:Q2047.cpp
// This one actually Q
2114 !!!!!
=======
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
>>>>>>> d83ac78 (Add Q14 solution):Q2114.cpp

#include<vector>
#include<string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int maximum = 0;


        for(int i = 0; i < n; i++) {
            int spaces = count(sentences[i].begin(), sentences[i].end(), ' ');
            int words = spaces + 1;

            maximum = max(maximum, words);

        }

        return maximum;
    }
};


/* class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int maximum = 0;

        for(int i = 0; i < n; i++) {

            int spaces = 0;

            for(int j = 0; j < n; j++) {

                if(sentences[i][j] == ' ') {
                    spaces++;
                }
            }

            int words = spaces + 1;
            maximum = max(maximum, words);
        }

        return maximum;
    }
};
    }
};
*/
