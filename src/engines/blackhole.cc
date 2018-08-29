/*
 * Copyright 2017-2018, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include "blackhole.h"

#define DO_LOG 0
#define LOG(msg) if (DO_LOG) std::cout << "[blackhole] " << msg << "\n"

namespace pmemkv {
namespace blackhole {

Blackhole::Blackhole() {
    LOG("Opened ok");
}

Blackhole::~Blackhole() {
    LOG("Closed ok");
}

int64_t Blackhole::Count() {
    LOG("Count");
    return 0;
}

int64_t Blackhole::CountLike(const string& pattern) {
    LOG("Count like pattern=" << pattern);
    return 0;
}

void Blackhole::Each(void* context, KVEachCallback* callback) {
    LOG("Each");
}

void Blackhole::EachLike(const string& pattern, void* context, KVEachCallback* callback) {
    LOG("Each like pattern=" << pattern);
}

KVStatus Blackhole::Exists(const string& key) {
    LOG("Exists for key=" << key);
    return NOT_FOUND;
}

void Blackhole::Get(void* context, const string& key, KVGetCallback* callback) {
    LOG("Get key=" << key);
}

KVStatus Blackhole::Put(const string& key, const string& value) {
    LOG("Put key=" << key << ", value.size=" << to_string(value.size()));
    return OK;
}

KVStatus Blackhole::Remove(const string& key) {
    LOG("Remove key=" << key);
    return OK;
}

} // namespace blackhole
} // namespace pmemkv
