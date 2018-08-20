#ifndef _LUOGU_HPP
#define _LUOGU_HPP 1

#include <cstdlib>
#include <fstream>

#define LG_CZ(X) #X
#define LG_KKK(A, B) A##B
#define LG_LTT(A, B, C) A##B##C
#define LG_RXZ(A, B, C, D) A##B##C##D

#define LG_SYS ::LG_LTT(sy, st, em)
#define LG_IFS std::LG_LTT(if, str, eam)
#define LG_OFS std::LG_LTT(of, str, eam)

#endif /* _LUOGU_HPP */
