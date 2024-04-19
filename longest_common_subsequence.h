#include <string>
#include <vector>

// finding the length of the longest common subsequence of first_word and second_word
int longest_common_subsequence(const std::string& first_word, const std::string& second_word) {

    // building 2d-array for DP
    int rows = std::ssize(first_word);
    int columns = std::ssize(second_word);
    std::vector<std::vector<int>> answer(rows + 1, std::vector<int> (columns + 1));

    // initializing the base values for DP
    answer[0][0] = 0;
    for (int i = 0; i <= rows; ++i) {
        answer[i][0] = 0;
    }
    for (int j = 0; j <= columns; ++j) {
        answer[0][j] = 0;
    }

    // solving through DP
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            answer[i][j] = std::max(answer[i - 1][j], answer[i][j - 1]);
            if (first_word[i - 1] == second_word[j - 1]) {
                answer[i][j] = std::max(answer[i][j], answer[i - 1][j - 1] + 1);
            }
        }
    }

    // returning the answer
    return answer[rows][columns];
}