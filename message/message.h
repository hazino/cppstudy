#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>
#include <json/json.h>

class message {
public:
     message() = default;
     virtual ~message() = default;
     virtual bool parse(const std::string& data) { (void)data; return false; }
     virtual bool parse(const std::vector<uint8_t> data) { (void)data; return false; }
     virtual std::vector<uint8_t> serialize() const { return std::vector<uint8_t>(); }
     Json::Value to_json() const;
};

#endif
