// Copyright 2021-2022 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <llvm/IRReader/IRReader.h>

#include <filesystem>

#include "builder.hpp"

namespace alangvm {

class LLVMRunner {
  llvm::ExecutionEngine* m_execution_engine;

 public:
  explicit LLVMRunner(std::unique_ptr<llvm::Module> module) {
    llvm::InitializeAllTargets();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeNativeTarget();

    auto& context = module->getContext();
    m_execution_engine = llvm::EngineBuilder(std::move(module)).setEngineKind(llvm::EngineKind::JIT).create();

    auto path = std::getenv("ALANG_PATH");
    if (path) {
      llvm::SMDiagnostic error;
      for (auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().string().ends_with(".ll")) {
          auto ext = llvm::parseIRFile(llvm::StringRef(entry.path()), error, context);
          m_execution_engine->addModule(std::move(ext));
        }
      }
    }
  }

  ~LLVMRunner() { delete m_execution_engine; }

  int run_function(const std::string& name) {
    auto main = m_execution_engine->FindFunctionNamed(llvm::StringRef(name));
    auto result = m_execution_engine->runFunction(main, {});

    return result.IntVal.getLimitedValue();
  }

  int run_main() { return run_function("main"); }
};

}  // namespace alangvm
