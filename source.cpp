#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return std::string(*itr);
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    std::string input;
    std::getline(std::cin, input); // read from stdin
    std::string delimiter = getCmdOption(argv, argv + argc, "--delimiter");

    if (delimiter.empty()) {
        delimiter = " "; // default delimiter is space
    } else if (delimiter == "\\n") {
        delimiter = "\n"; // treat as line ending
    } else if (delimiter == "\\t") {
        delimiter = "\t"; // treat as tab
    }

    if (!input.empty()) {
        for (size_t i = 0; i < input.size(); ++i) {
            if (i != 0) {
                std::cout << delimiter;
            }
            std::cout << static_cast<int>(input[i]);
        }
    } else {
        std::cout << "No input string was given." << std::endl;
    }

    return 0;
}