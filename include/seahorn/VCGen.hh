#pragma once
#include <seahorn/OpSem.hh>
namespace seahorn {
  class CpEdge;
  /**
   * Verification Condition (VC) generator for loop-free code.  Given
   * an operational semantics (OpSem) and loop-free code block,
   * generates a formula that encodes all executions through the code
   * block according to the given operational semantics.
   */
  class VCGen
  {
    OpSem &m_sem;
    Expr trueE;

    void execEdgBb (SymStore &s, const CpEdge &edge,
                    const BasicBlock &bb, ExprVector &side, bool last = false);

  public:
    VCGen (OpSem &sem)
      : m_sem (sem) { trueE = mk<TRUE> (m_sem.getExprFactory ()); }

    virtual void execCpEdg (SymStore &s, const CpEdge &edge, ExprVector &side);


  };
}