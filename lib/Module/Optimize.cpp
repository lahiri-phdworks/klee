// FIXME: This file is a bastard child of opt.cpp and llvm-ld's
// Optimize.cpp. This stuff should live in common code.


//===- Optimize.cpp - Optimize a complete program -------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements all optimization of the linked module for llvm-ld.
//
//===----------------------------------------------------------------------===//

#include "ModuleHelper.h"

#include "llvm/IR/Module.h"

using namespace klee;
void klee::optimiseAndPrepare(bool OptimiseKLEECall, bool Optimize,
                              SwitchImplType SwitchType, std::string EntryPoint,
                              llvm::ArrayRef<const char *> preservedFunctions,
                              llvm::Module *module) {
  (void)OptimiseKLEECall;
  (void)Optimize;
  (void)SwitchType;
  (void)preservedFunctions;

  // The legacy optimization pipeline uses pass factory APIs that were removed
  // in newer LLVM releases. Keep the required module preparation step here so
  // LLVM 17+ builds can execute modules instead of aborting on this stub.
  injectStaticConstructorsAndDestructors(module, EntryPoint);
}
