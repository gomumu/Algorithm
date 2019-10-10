
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::string &s) {
    std::vector<int> countinuos_number;
    size_t counter = 0;
    size_t n;
    for (int i = 0; i < s.size(); ++i) {
        if (i != 0) {
            auto prev_char = s.at(i - 1);
            auto current_char = s.at(i);
            if (prev_char != current_char) {
                countinuos_number.push_back(counter);
                counter = 0;
            }
        }
        ++counter;
    }
    countinuos_number.push_back(counter);  // last count

    size_t value = 0;
    size_t index = 0;
    auto count = [&]() -> bool {
        if (countinuos_number[index] > 2) {
            countinuos_number[index] = 2;
            value += countinuos_number[index];
            return true;
        } else {
            value += countinuos_number[index];
            ++index;
            return false;
        }
    };

    size_t max_value = 0;
    while (index < countinuos_number.size()) {
        if (count()) {
            max_value = std::max(max_value, value);
            value = 0;
        }
    }
    return std::max(max_value, value);
}

struct tree {
    int x;
    tree* l;
    tree* r;
    tree(int x, tree* l, tree* r) : x(x), l(l), r(r) {};
};

int distinctPathHeight(tree * T, std::vector<int> path_num) {
    size_t left = 0, right = 0;
    size_t distinct_path_height = 1;

    for (int num : path_num) {
        if (num == T->x) {
            return 0;
        }
    }
    path_num.push_back(T->x);

    if (T->l == nullptr && T->r == nullptr) {
        return 1;
    }

    if (T->l != nullptr) {
        left = distinctPathHeight(T->l, path_num);
    }

    if (T->r != nullptr) {
        right = distinctPathHeight(T->r, path_num);
    }

    distinct_path_height += std::max(left, right);
    return distinct_path_height;
}

int solution(tree * T) {
    std::vector<int> path_num;
    path_num.push_back(T->x);
    size_t distinct_path_height = 1;
    size_t left = 0, right = 0;
    if (T->l != nullptr) {
        left = distinctPathHeight(T->l, path_num);
    }
    if (T->r != nullptr) {
        right = distinctPathHeight(T->r, path_num);
    }

    distinct_path_height += std::max(left, right);
    return distinct_path_height;
}

std::string solution(int U, int L, std::vector<int> &C) {
    std::string upper = "";
    std::string lower = "";

    bool impossible = false;
    for (auto c : C) {
        if (c == 2) {
            upper += "1";
            lower += "1";
            --U, --L;
        } else if (c == 1) {
            if (U > L) {
                --U;
                upper += "1";
                lower += "0";
            } else {
                --L;
                upper += "0";
                lower += "1";
            }
        } else {
            upper += "0";
            lower += "0";
        }
        if (U < 0 || L < 0) {
            impossible = true;
            break;
        }
    }

    std::string val = "";
    if (impossible || U != 0 || L != 0) {
        val = "IMPOSSIBLE";
    } else {
        val = upper + "," + lower;
    }
    return val;
}

int main() {
    ////Example1
    //std::string s = "babbababbbaaabbabbabbabb";
    //solution(s);

    ////Example2
    //tree H(2, nullptr, nullptr);
    //tree I(5, nullptr, nullptr);
    //tree J(6, nullptr, nullptr);
    //tree D(3, &H, nullptr);
    //tree E(6, nullptr, nullptr);
    //tree F(3, nullptr, nullptr);
    //tree G(1, &I, &J);
    //tree B(2, &D, &E);
    //tree C(3, &F, &G);
    //tree A(1, &B, &C);
    //solution(&A);

    //Example3
    int U = 8;
    int L = 0;
    std::vector<int> C1 = { 2, 2, 2, 2};
    std::string val = solution(U, L, C1);
    printf(val.c_str());
    return 0;
}