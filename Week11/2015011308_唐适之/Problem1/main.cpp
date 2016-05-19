#include <ctime>
#include <cctype>
#include <fstream>
#include <iostream>
#include "kmp.h"
#include "rk.h"

struct file_t
{
    std::string name, content;
};

static std::vector<file_t> loadFilesFromList(std::string list)
{
    std::ifstream listStream(list);
    std::string name;
    std::vector<file_t> ret;
    while (listStream >> name)
    {
        std::ifstream is(name);
        std::string raw = std::string(
            std::istreambuf_iterator<char>(is),
            std::istreambuf_iterator<char>()
        ); // use constructor explicitly to avoid ambiguity

        ret.push_back(file_t());
        ret.back().name = name;
        for (char c : raw)
            if (! isspace(c))
                ret.back().content += c;
    }
    return ret;
}

static void match(PatternMatch *matcher, const std::vector<file_t> &patterns, const std::vector<file_t> &files)
{
    for (const auto &p : patterns)
        matcher->addPattern(p.content);
    for (const auto &f : files)
    {
        matcher->match(f.content);
        std::cout << "match file " << f.name << " :" << std::endl;
        for (const auto &item : matcher->getResult())
            std::cout << "  pattern \"" << item.first << "\" hits " << item.second << " time(s)" << std::endl;
    }
}

int main()
{
    auto files = loadFilesFromList("filelist.txt");
    auto patterns = loadFilesFromList("patternlist.txt");

    PatternMatch *matcher = NULL;

    clock_t startKMP = clock(); // ctime is enough, we don't need complicated STL
    std::cout << "KMP :" << std::endl;
    matcher = new KMP();
    match(matcher, patterns, files);
    delete matcher;
    matcher = NULL;
    clock_t endKMP = clock();
    std::cout << "=======================" << std::endl;

    clock_t startRK = clock();
    std::cout << "RK :" << std::endl;
    matcher = new RK();
    match(matcher, patterns, files);
    delete matcher;
    matcher = NULL;
    clock_t endRK = clock();
    std::cout << "=======================" << std::endl;

    std::cout << "time :" << std::endl
              << "  KMP = " << (float)(endKMP - startKMP) / CLOCKS_PER_SEC << " seconds" << std::endl
              << "  RK = " << (float)(endRK - startRK) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

