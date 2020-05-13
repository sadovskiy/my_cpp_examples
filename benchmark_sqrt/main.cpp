// Тест на скорость вычисления обратного квадратного корня тремя способами:
// 1) используя обычную функцию sqrtf() из библиотеки cmath;
// 2) используя алгоритм быстрого обратного квадратного корня;
// 3) используя SSE инструкцию RSQRTSS реализованную аппаратно.
// Пример взят из Википедии
// https://ru.wikipedia.org/wiki/Быстрый_обратный_квадратный_корень
// Ещё интересно
// https://stackoverflow.com/questions/1528727/why-is-sse-scalar-sqrtx-slower-than-rsqrtx-x

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

enum { BENCHMARK_SIZE = 1000000000 };

using Func = float (*)();

void testTime(const char* name, Func func)
{
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end   = chrono::high_resolution_clock::now();
    auto diff = end - start;
    cout << name
         << ": "
         << chrono::duration <double, milli> (diff).count()
         << " ms"
         << endl;
}

inline float Q_rsqrt(float number)
{
    const float x2 = number * 0.5F;
    constexpr float threehalfs = 1.5F;

    union {
        float f;
        uint32_t i;
    } conv = {number}; // member 'f' set to value of 'number'.
    conv.i  = 0x5f3759df - ( conv.i >> 1 );
    conv.f  *= ( threehalfs - ( x2 * conv.f * conv.f ) );
    return conv.f;
}

inline float sseSqrt(float x)
{
    float y;

    asm ("rsqrtss %[x], %%xmm0;"   // EVAL rsqrtss of "x" and store result in xmm0
         "movss %%xmm0, %[y];"     // LOAD value from xmm0 into y
            :                      // Input param
            : [ x ] "m" ( x ), [ y ] "m" ( y ) // Output param
            : "%xmm0"
            );

    return y;
}

float normalBenchmark()
{
    float y = 0;
    float x = 1.0;
    for (size_t i = 0; i < BENCHMARK_SIZE; ++i) {
        y = 1.0f / sqrtf(x);
        x += 0.001f;
    }
    return y;
}

float fastBenchmark()
{
    float y = 0;
    float x = 1.0;
    for (size_t i = 0; i < BENCHMARK_SIZE; ++i) {
        y = Q_rsqrt(x);
        x += 0.001f;
    }
    return y;
}

float sseBenchmark()
{
    float y = 0;
    float x = 1.0;
    for (size_t i = 0; i < BENCHMARK_SIZE; ++i) {
        y = sseSqrt(x);
        x += 0.001f;
    }
    return y;
}

int main()
{
    testTime("Normal", normalBenchmark);
    testTime("Fast  ", fastBenchmark);
    testTime("SSE   ", sseBenchmark);

    return 0;
}
