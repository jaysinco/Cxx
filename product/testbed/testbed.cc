#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <future>
#include <functional>
#include <execution>
#include "common/debugging/print.h"
using namespace std::literals;
using namespace std::placeholders;

int main(int argc, char *argv[])
{
    TRY_BEGIN
    google::InitGoogleLogging(argv[0]);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = 0;
    CATCH_ALL
}