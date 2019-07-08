#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/DebugLoc.h"

using namespace std;
using namespace llvm;

namespace {
 struct debuginfo : public FunctionPass {
   static char ID;
   debuginfo() : FunctionPass(ID) {}

   bool runOnFunction(Function &F) override {
     errs() << "I saw a function called " << F.getName() << "!\n";
     for (auto &B : F) {
       errs() << "1\n";
       for (auto &I : B) {
         errs() << I << "\n";
       
     
         if (DILocation *Loc = I.getDebugLoc()) {
           if (!Loc) {
             errs() << I << " Loc is null" << "\n";
             continue;
           }
           // Here I is an LLVM instruction
           unsigned Line = Loc->getLine();
           StringRef File = Loc->getFilename();
           StringRef Dir = Loc->getDirectory();
           errs() << I << ", " << File << ":" << Line << "\n";
         }
       }
     }
     errs() << "2";
     return false;
   }
 };
}

char debuginfo::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerdebuginfo(const PassManagerBuilder &,
                        legacy::PassManagerBase &PM) {
 PM.add(new debuginfo());
}
static RegisterStandardPasses
 RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                registerdebuginfo);

