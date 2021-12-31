// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <functional>
#include <string>

namespace framework::stdio {
void server(std::function<void(const std::string &)>);
}  // namespace framework::stdio
