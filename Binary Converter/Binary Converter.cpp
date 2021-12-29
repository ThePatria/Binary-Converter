#include <iostream>
#include <string>
#include <cmath>

std::string binma();
void bindec(std::string);
void decbin();
bool checkbin(std::string);
char chooses();

int main() {
    std::string stay;
    char choose, conf;
    bool checking;
    do {
    chess:
        choose = chooses();
        std::cout << "\n";
        switch (choose) {
        case '1':
            stay = binma();
            checking = checkbin(stay);
            if (checking)
                bindec(stay);
            else {
                std::cout << "Invalid" << std::endl;
                std::cout << "\n";
            }
            break;
        case '2':
            decbin();
            break;
        default:
            goto chess;
        }
        std::cout << "Lagi?(Y/N): "; std::cin >> conf;
        std::cout << "\n";
    } while (conf == 'y' || conf == 'Y');
    return 0;
}

std::string binma() {
    std::string violin;
    std::cout << "Masukkan binary: ";
    std::cin >> violin;
    return violin;
}

void bindec(std::string in) {
    int res = 0, len = in.length();
    for (int i = 0; i < len; i++)
        if (in.at(i) == '1')
            res += pow(2, len - i - 1);

    std::cout << "Decimal: " << res << std::endl;
}

bool checkbin(std::string in) {
    size_t len = in.length(); bool sit = true;
    for (int i = 0; i < len; i++)
        if (in.at(i) != '1' && in.at(i) != '0')
            sit = false;

    return sit;
}

char chooses() {
    char a;
    std::cout << "(1) Binary to Decimal" << std::endl;
    std::cout << "(2) Decimal to Binary" << std::endl;
    std::cout << "Choose: ";
    std::cin >> a;
    return a;
}

void decbin() {
    int sitdown;
    std::string binary = "";
    std::cout << "Masukkan Angka: ";
    std::cin >> sitdown;
    while (sitdown != 0) {
        if (sitdown % 2 == 0)
            binary.insert(0, "0");
        else
            binary.insert(0, "1");
        sitdown /= 2;
    }
    std::cout << "Binary: " << binary << "\n";
}