#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <stdexcept>

using namespace std;

// #define DEBUG_EN

#ifdef DEBUG_EN
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

namespace navigation {

    static const std::uint64_t CLOSING_PARANTHESIS_SCORE_VALUE = 3;
    static const std::uint64_t CLOSING_SQUARE_BRACKET_SCORE_VALUE = 57;
    static const std::uint64_t CLOSING_CURLY_BRACKET_SCORE_VALUE = 1197;
    static const std::uint64_t CLOSING_ANGLE_BRACKET_SCORE_VALUE = 25137;


    std::vector<std::string> GetSyntaxChuckVector(const std::string& input_file) {
        std::ifstream infile(input_file);
        std::vector<std::string> lines;
        if (!infile.is_open()) {
            // Handle Error
            throw std::runtime_error("Input file failed to open !");
        }

        std::string line;
        while (std::getline(infile, line)) {
            lines.push_back(line);
        }
        infile.close();
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
                DEBUG_MSG("Character is : " << character << "\n" );
                auto item = open_close_characters.find(character);
                if (item != open_close_characters.end()) { // Closing character found
                    DEBUG_MSG("Closing character found" << "\n" );
                    // Check top in stack and pop accordingly
                    if (!syntax_stack.empty()) {
                        //char top_character = ;
                        if (syntax_stack.top() == item->second) {
                            DEBUG_MSG("Matching stack element.Removing from stack" << "\n" );
                            // Pair is OK. So Pop element
                            syntax_stack.pop();
                        } else {
                            DEBUG_MSG("Mismatch stack element!" << "\n" );
                            auto elem = syntax_error_count.find(item->first);
                            if (elem != syntax_error_count.end()) {
                                elem->second = elem->second + 1;
                            }
                            break;
                        }
                    }
                } else { // Opening character found so Push map value to stack
                    DEBUG_MSG("Opening character found:" << character << ' ' <<"Adding it to stack" << "\n");
                    syntax_stack.push(character);
                }
            }
        }

        std::uint64_t total_syntax_score = 0;
        for(const auto& elem : syntax_error_count) {
            DEBUG_MSG("Syntax score map data: " << elem.first << ' ' << elem.second << "\n");
            switch (elem.first)
	        {
	            case ')':
		            total_syntax_score += elem.second * CLOSING_PARANTHESIS_SCORE_VALUE; break;

	            case '>':
		            total_syntax_score += elem.second * CLOSING_ANGLE_BRACKET_SCORE_VALUE; break;

	            case ']':
		            total_syntax_score += elem.second * CLOSING_SQUARE_BRACKET_SCORE_VALUE; break;

                case '}':
		            total_syntax_score += elem.second * CLOSING_CURLY_BRACKET_SCORE_VALUE; break;

	            default:
		            std::cerr << "Unknown value" <<"\n"; break;

	        }
        }

    return total_syntax_score;
}
} // namespace navigation


int main(int argc, char* argv[]) {

    if (argc == 2) {
        const std::string navi_file_path = argv[1];
        auto syntax_score = navigation::RetriveSyntaxScore(navi_file_path);
        cout << "Total syntax score : " << syntax_score <<"\n";
    } else {
        std::cerr << "Usage: " << "syntax_scoring <input file path>" << std::endl;
    }
    return EXIT_SUCCESS;
}