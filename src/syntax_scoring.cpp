#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

namespace navigation {

    std::vector<std::string> GetSyntaxChuckVector(const std::string& input_file) {
        std::ifstream infile(input_file);
        std::vector<std::string> lines;
        if (!infile.is_open()) {
            // Handle Error
        }

        std::string line;
        while (std::getline(infile, line)) {
            lines.push_back(line);
            //cout << "Line is :" << line <<"\n";
        }

        return lines;
    }

    std::uint64_t RetriveSyntaxScore(const std::string& file_path) {

        std::map<std::int8_t,std::int8_t> open_close_characters =
        {
            {']', '['},
            {'}', '{'},
            {'>' ,'<'},
            {')', '('}
        };

         std::map<std::int8_t,std::uint64_t> syntax_error_count =
        {
            {']', 0},
            {'}', 0},
            {'>', 0},
            {')', 0}
        };

        std::stack<std::int8_t> syntax_stack;

        auto lines = GetSyntaxChuckVector(file_path);


        for (const auto &line_by_line : lines) {
            for(auto &character : line_by_line) {
                cout << "Character is :" << character << "\n";
                auto item = open_close_characters.find(character);
                if (item != open_close_characters.end()) { // Closing character found
                    // Check top in stack and pop accordingly
                    if (!syntax_stack.empty()) {
                        //char top_character = ;
                        if (syntax_stack.top() == item->second) {
                            // Pair is OK. So Pop element
                            syntax_stack.pop();
                        } else {
                            auto elem = syntax_error_count.find(item->first);
                            if (elem != syntax_error_count.end()) {
                                elem->second = elem->second + 1;
                            }
                            break;
                        }
                    }

                } else { // Opening character found so Push map value to stack
                    cout << "Opening char found:" << character << ' ' <<"Adding it to stack" << "\n";
                    syntax_stack.push(character);
                }
            }
        }

        std::uint64_t total_syntax_score = 0;
        for(const auto& elem : syntax_error_count) {
            switch (elem.first)
	        {
	            case ')':
		            total_syntax_score += elem.second * 3; break;

	            case '>':
		            total_syntax_score += elem.second * 25137; break;

	            case ']':
		            total_syntax_score += elem.second * 57; break;

                case '}':
		            total_syntax_score += elem.second * 1197; break;

	            default:
		            cout<<"Unknown character"; break;

	        }
        }
    cout << "Total syntax score : " << total_syntax_score <<"\n";
    return total_syntax_score;
}
} // namespace navigation


int main(int argc, char* argv[]) {

    if (argc == 2) {
        const std::string navi_file_path = argv[1];
        auto syntax_score = navigation::RetriveSyntaxScore(navi_file_path);
    } else {
        std::cerr << "Usage: " << "syntax_scoring <input file path>" << std::endl;
    }
    return EXIT_SUCCESS;
}