#include <string>
#include <vector>

// finding the editing distance of first_word and second_word
int editing_distance(const std::string& first_word, const std::string& second_word) {

    // building 2d-array for DP
    int rows = std::ssize(first_word);
    int columns = std::ssize(second_word);
    std::vector<std::vector<int>> answer(rows + 1, std::vector<int> (columns + 1));

    // initializing the base values for DP
    answer[0][0] = 0;
    for (int i = 1; i <= rows; ++i) {
        answer[i][0] = i;
    }
    for (int j = 1; j <= columns; ++j) {
        answer[0][j] = j;
    }

    // solving through DP
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            answer[i][j] = std::min(answer[i - 1][j] + 1, answer[i][j - 1] + 1);
            if (first_word[i - 1] == second_word[j - 1]) {
                answer[i][j] = std::min(answer[i][j], answer[i - 1][j - 1]);
            } else {
                answer[i][j] = std::min(answer[i][j], answer[i - 1][j - 1] + 1);
            }
        }
    }

    // returning the answer
    return answer[rows][columns];
}