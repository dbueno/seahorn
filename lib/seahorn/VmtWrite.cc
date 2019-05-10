#include "seahorn/VmtWrite.hh"

#include "seahorn/HornifyModule.hh"
#include "seahorn/TransRelationDB.hh"

#include "seahorn/config.h"

#include "llvm/Support/CommandLine.h"

namespace seahorn {
char VmtWrite::ID = 0;

void VmtWrite::getAnalysisUsage(AnalysisUsage& au) const {
  au.addRequired<HornifyModule>();
  au.setPreservesAll();
}

template <typename Out, typename Key, typename Value> 
void setInfo (Out &out, Key &key, Value &val)
{
  out << "(set-info :" << key 
      << " \"" << val << "\"" << ")\n";
}

bool VmtWrite::runOnModule(Module& m) {
  ScopedStats _st_("VmtWrite");
  HornifyModule &hm = getAnalysis<HornifyModule> ();
  TransRelationDB &db  = hm.getTransRelationDB ();
  ExprFactory &efac = hm.getExprFactory ();
  ZSolver<EZ3> solver(hm.getZContext());

  db.loadZSolver(solver);

  solver.toSmtLib(m_out);
  //m_out << solver << "\n";
  m_out.flush();

  return false;
}

}
