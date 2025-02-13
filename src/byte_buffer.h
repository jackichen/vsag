
// Copyright 2024-present the vsag project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "vsag/allocator.h"

namespace vsag {
class ByteBuffer {
public:
    ByteBuffer(uint64_t size, Allocator* allocator) : allocator(allocator) {
        data = static_cast<uint8_t*>(allocator->Allocate(size));
    }

    ~ByteBuffer() {
        allocator->Deallocate(data);
    }

public:
    uint8_t* data;

    Allocator* allocator;
};
}  // namespace vsag
