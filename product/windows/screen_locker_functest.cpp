#include "screen_locker.h"
#include <thread>
#include <chrono>
#include "common/utility/logging.h"

int main(int argc, char *argv[])
{
    google::InitGoogleLogging(argv[0]);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = 0;
    if (!SetProcessDPIAware())
    {
        LOG_LAST_ERROR("failed to set process dpi aware");
    }
    std::thread(
        [] {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            ScreenLocker::Close();
        })
        .detach();
    ScreenLocker::Popup(
        "",
        u8"请输入密码: ",
        u8"D:\\Jaysinco\\Cxx\\product\\windows\\resources\\background.bmp",
        u8"D:\\Jaysinco\\Cxx\\product\\windows\\resources\\point.cur",
        false,
        false,
        500);
}