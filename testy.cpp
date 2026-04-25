#include <iostream>
#include <string>
#include "leveldb/db.h"
    int main() {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    if (!status.ok()) {
        std::cerr << "Failed to open database: " << status.ToString() <<
        std::endl;
        return 1;
    }
    leveldb::WriteOptions write_options;
    leveldb::ReadOptions read_options;
    // Put
    db->Put(write_options, "key1", "value1");
    db->Put(write_options, "key2", "value2");
    // Get
    std::string value;
    status = db->Get(read_options, "key1", &value);
    if (status.ok()) {
        std::cout << "key1 => " << value << std::endl;
    }
    // Delete
    db->Delete(write_options, "key2");
    delete db;
    return 0;
}
