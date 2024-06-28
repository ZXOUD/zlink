/*
 * This file is part of the software and assets of HK ZXOUD LIMITED.
 * @copyright (c) HK ZXOUD LIMITED https://www.zxoud.com
 * Author: yushou-cell(email:2354739167@qq.com)
 * create: 20240620
 * FilePath: /zlink/head/system.hpp
 * Description: some system tools
 */
#pragma once
#include <mimalloc-override.h>
#include <czmq.h>
#include <chrono>
#include <thread>
#include <filesystem>
#include <fstream>
#include <glog/logging.h>
#include <libunwind.h>
#include <hiredis/hiredis.h>
#include <format>
#include "nlohmann/json.hpp"
#include <unordered_map>
#include <utility>
#include <variant>
#include <pqxx/pqxx>
#define WORKER_READY "\001"

class NonCopyable
{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
    NonCopyable(NonCopyable &&) = delete;
    NonCopyable &operator=(NonCopyable &&) = delete;
};

struct RedisReplyWrap : NonCopyable
{
    redisReply *reply = nullptr;
    inline ~RedisReplyWrap()
    {
        if (reply != nullptr)
        {
            freeReplyObject(reply);
            reply = nullptr;
        }
    }
};
