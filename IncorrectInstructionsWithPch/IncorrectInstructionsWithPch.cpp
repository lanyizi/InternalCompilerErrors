#include "pch.h"

int main()
{
    auto text = std::string{};
    if (text.empty())
    {
        text.resize(1);
    }
    /*
        The following line of code:

        text.resize(text.find_last_not_of('\0') + 1);

        Will generate these instructions:
    00FB5231  push        0
    00FB5233  push        0FFFFFFFFh
    00FB5235  push        0
    00FB5237  lea         ecx,[text]
    00FB523A  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::find_last_not_of (0FB1442h)
    00FB523F  xor         ecx,ecx
    00FB5241  add         eax,1
    00FB5244  setb        cl
    00FB5247  neg         ecx
    00FB5249  or          ecx,eax
    00FB524B  push        ecx
    00FB524C  lea         ecx,[text]
    00FB524F  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::resize (0FB13CFh)

        If `find_last_not_of()` returned `npos` (i.e. -1),
        adding one to the result should yield 0.
        But actually, with `setb cl; neg ecx; or ecx,eax`, we will still get -1.
    */
    // will throw std::length_error
    text.resize(text.find_last_not_of('\0') + 1);
}