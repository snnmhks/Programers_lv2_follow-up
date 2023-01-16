#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 단순한 끝말잇기 게임이라서 따로 논리는 설명하지 않겠다.

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int wrongIndex = 0;
    int length = words.size();
    
    for (int i = 1; i < length; i++)
    {
        if (words[i-1][words[i-1].length()-1] != words[i][0])
        {
        // 직전 마지막 단어하고 지금 첫단어가 다르면 지금 순서를 기억한다. 
            wrongIndex = i;
            break;
        }
        for (int j = 0; j < i; j++)
        {
            if (words[j] == words[i])
            {
            // 이전까지의 단어와 지금 단어가 같으면 지금 순서를 기억한다.
                wrongIndex = i;
                break;
            }
        }
        if (wrongIndex != 0)
        {
            break;
        }
    }
    answer.push_back(wrongIndex%n + 1); // 기억한 순서 % 인원 + 1을 하면 누가 틀렸는지 알 수 있다.
    answer.push_back(wrongIndex/n + 1); // 기억한 순서 / 인원 + 1을 하면 몇번째 턴에 틀렸는지 알 수 있다.
    if (wrongIndex == 0)
    {
    // 한번도 틀린게 없으면 0으로 바꾼다.
        answer[0] = 0;
        answer[1] = 0;
    }
    return answer;
}
