# AoC - Syntax Scoring 

This assigment aims to explore the possible solution implemented in C++ to AoC problem listed here following link
https://adventofcode.com/2021/day/10


## Motivation

Advent of Code aka AoC is an annual Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like.I was challended to solve one of problem as part of company skill set evaluation. Being an Embedded developer, I choose C++ programming language to solve this problem.I hereby declare that I haven't used or looked into any other solutions online for completing this task,only used cpp reference sites for referring syntax of containers used in program   


## Method and results

After successful compilation,a program named 'syntax_scoring' accepts parameter as file where inputs are provided.Once executed, program outputs the total syntax score found for corresponding input.

Program assume following input factors
* Input contains only combination of 8-characters {,},[,],(,),<,> 
* Syntax total score falls in range that std::uint64_t can accomodate

### Host Machine/Processor/OS/Compiler/IDE used 

* Processor - 64-bit Intel(R) Core(TM) i7-6920HQ CPU @ 2.90GHz
* OS - UBUNTU 18.04 LTS/x86_64
* GCC or G++ version - gcc version 7.5.0
* IDE - Visual Studio Code https://code.visualstudio.com/

## Repository overview

Overview of the directory structure and files
```
├── README.md
└── src
    ├── syntax_scoring  --> Final executable binary 
    ├── syntax_scoring.cpp
    └── tests
        ├── input_sample_1.txt
        ├── input_sample_2.txt
        ├── input_sample_3.txt
        ├── input_sample_4.txt
        └── input_sample_5.txt
```

## Running instructions
1. Open source in VS code(.vscode is included as it has tasks.json which configures GCC and binary executable name)
2. After selecting cpp file(syntax_scoring.cpp) ,Go to Terminal -> Run Build Task
3. After success build, execute binary : syntax_scoring <input file>
   E.g syntax_scoring tests/input_sample_1.txt
4. Output will be shown in terminal which corresponds to total syntax score for corresponding input provided

Note : Debug logs are disable by default. To enable traces, uncomment DEBUG_EN in syntax_scoring.cpp file


## References
* https://en.cppreference.com/w/
* https://adventofcode.com/2021/day/10
* https://www.cplusplus.com/



