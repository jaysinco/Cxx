#include "common/utility/base.h"

int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = 0;
}