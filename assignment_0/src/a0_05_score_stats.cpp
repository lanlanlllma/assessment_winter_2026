#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<std::pair<std::string, int>> students(n);
    int max_score = -1;
    std::string top_name;
    int top_score = -1;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int score;
        if (!(std::cin >> name >> score)) {
            return 0;
        }

        students[i] = {name, score};
        sum += score;

        if (score > max_score) {
            max_score = score;
            top_name = name;
            top_score = score;
        }
    }

    double avg = static_cast<double>(sum) / n;

    std::cout << "top=" << top_name << " " << top_score << "\n";
    std::cout << std::fixed << std::setprecision(2) << "avg=" << avg << std::endl;

    return 0;
}