#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include "common/debugging/print.h"

int main(int argc, char *argv[])
{
    TRY_BEGIN
    google::InitGoogleLogging(argv[0]);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = 0;
    using bsoncxx::builder::basic::kvp;
    using bsoncxx::builder::basic::make_document;
    mongocxx::instance inst;
    const auto uri = mongocxx::uri{};
    auto client = mongocxx::client{uri};
    auto admin = client["admin"];
    auto result = admin.run_command(make_document(kvp("isMaster", 1)));
    LOG(INFO) << bsoncxx::to_json(result) << std::endl;
    CATCH_ALL
}
