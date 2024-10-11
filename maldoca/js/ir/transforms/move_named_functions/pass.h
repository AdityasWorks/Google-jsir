// Copyright 2023 Google LLC
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

#ifndef MALDOCA_JS_IR_TRANSFORMS_MOVE_NAMED_FUNCTIONS_PASS_H_
#define MALDOCA_JS_IR_TRANSFORMS_MOVE_NAMED_FUNCTIONS_PASS_H_

#include <vector>

#include "mlir/IR/Operation.h"
#include "mlir/Pass/Pass.h"

namespace maldoca {

// Recursively moves all JsirFunctionDeclarationOps to the beginning of the
// enclosing region. Conceptually this means moving all function declarations to
// the beginning of the block scope.
//
// maldoca:google3-begin(mentions internal system)
//
// Reordering function declarations does not change code semantics, but has a
// big impact on the AST structure and therefore AST similarity. DejaScript
// depends on the exact structure of the AST to compute similarity features (see
// go/jscat-norm-reqs).
//
// maldoca:google3-end
void MoveNamedFunctions(mlir::Operation *root);

struct MoveNamedFunctionsPass
    : public mlir::PassWrapper<MoveNamedFunctionsPass, mlir::OperationPass<>> {
  void runOnOperation() override {
    mlir::Operation *root = getOperation();
    MoveNamedFunctions(root);
  }
};

}  // namespace maldoca

#endif  // MALDOCA_JS_IR_TRANSFORMS_MOVE_NAMED_FUNCTIONS_PASS_H_
