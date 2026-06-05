class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stCircleFreq=0, stSquareFreq=0;

        for(int i=0;i<students.size();i++) {
            if(students[i]==0) stCircleFreq++;
            else stSquareFreq++;
        }

        for(int i=0;i<sandwiches.size();i++) {
            if(sandwiches[i]==0) {
                stCircleFreq--;
            }
            else {
                stSquareFreq--;
            }

            if(stCircleFreq==-1 || stSquareFreq==-1) {
                return sandwiches.size()-i;
            }
        }

        return 0;
    }
};