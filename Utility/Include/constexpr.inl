#pragma once

#if __cplusplus < 201300
#define CPP_14_CONSTEXPR
#else
#define CPP_14_CONSTEXPR constexpr
#endif