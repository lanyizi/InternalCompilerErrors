module;
#include "pch.h"
export module Module;

namespace Lanyi::Test
{
    export
    {
        template<typename Callable>
        concept Baka = std::is_invocable_r_v<
            std::string_view,
            Callable,
            std::string_view,
            std::string_view>
            and std::move_constructible<Callable>;
    }
}

