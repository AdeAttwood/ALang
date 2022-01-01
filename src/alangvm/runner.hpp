// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include "builder.hpp"

namespace alangvm {

class LLVMRunner {
  llvm::ExecutionEngine* m_execution_engine;

 public:
  explicit LLVMRunner(std::unique_ptr<llvm::Module> module) {
    llvm::InitializeAllTargets();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeNativeTarget();

    m_execution_engine = llvm::EngineBuilder(std::move(module)).setEngineKind(llvm::EngineKind::JIT).create();
  }

  int run_function(const std::string& name) {
    auto main = m_execution_engine->FindFunctionNamed(llvm::StringRef(name));
    auto result = m_execution_engine->runFunction(main, {});

    return result.IntVal.getLimitedValue();
  }

  int run_main() { return run_function("main"); }
};

}  // namespace alangvm
