#ifndef BV_FLATHORNIFYFUNCTION_H
#define BV_FLATHORNIFYFUNCTION_H

#include "seahorn/HornifyFunction.hh"
#include "llvm/IR/Function.h"

#include "ufo/Expr.hpp"
#include "ufo/Smt/EZ3.hh"
#include "seahorn/BvOpSem.hh"
#include "seahorn/LiveSymbols.hh"

namespace seahorn
{
  using namespace expr;
  using namespace llvm;
  

  class BvFlatLargeHornifyFunction : public HornifyFunction
  {
  public:
    BvFlatLargeHornifyFunction (HornifyModule &parent,
                              bool interproc = false) :
      HornifyFunction (parent, interproc) {}

    virtual void runOnFunction (Function &F);

  private:
    void walkToRoots(ExprSet& vars, SymStore& s, ExprVector& rooted_out);
  };

  class BvFlatSmallHornifyFunction : public HornifyFunction
  {
  public:
    BvFlatSmallHornifyFunction (HornifyModule &parent,
                              bool interproc = false) :
      HornifyFunction (parent, interproc) {}

    virtual void runOnFunction (Function &F);
  };

}




#endif /* FLATHORNIFYFUNCTION_H */
