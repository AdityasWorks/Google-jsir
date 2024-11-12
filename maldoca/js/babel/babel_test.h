// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MALDOCA_JS_BABEL_BABEL_TEST_H_
#define MALDOCA_JS_BABEL_BABEL_TEST_H_

#include <functional>
#include <memory>
#include <string>

#include "gtest/gtest.h"
#include "maldoca/js/babel/babel.h"
#include "maldoca/js/babel/babel.pb.h"

namespace maldoca {

struct BabelTestParams {
  std::function<std::unique_ptr<Babel>()> babel_factory;
  std::string stack_overflow_error_pbtxt;
};

class BabelTest : public testing::TestWithParam<BabelTestParams> {};

}  // namespace maldoca

#endif  // MALDOCA_JS_BABEL_BABEL_TEST_H_
