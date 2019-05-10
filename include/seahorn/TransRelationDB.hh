#ifndef _TRANS_RELATION_DB__H_
#define _TRANS_RELATION_DB__H_

#include "llvm/Support/raw_ostream.h"

#include <boost/range.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/container/flat_set.hpp>

#include "ufo/Expr.hpp"
#include "seahorn/Support/Stats.hh"

#include <algorithm>
#include <map>


namespace seahorn {
using namespace llvm;
using namespace expr;

class TransRelationDB;

class TransRelationDB {
 public:
  TransRelationDB(ExprFactory& efac) : m_efac(efac) {}

  void registerLocation(Expr loc);

  void addTransition(Expr condition, ExprVector vals);

  std::map<Expr, ExprVector> getTransitions() {
    return m_transitions;
  }

  friend llvm::raw_fd_ostream& operator<<(llvm::raw_fd_ostream&, const TransRelationDB&);

  template <typename S>
  void loadZSolver(S &solver) {
    for (auto& t : getTransitions()) {
      for (auto& c : t.second) {
        solver.assertExpr(boolop::limp(t.first, c));
      }
    }
  }

 private:
  ExprFactory& m_efac;
  ExprVector m_locations;
  std::map<Expr, ExprVector> m_transitions;
};

llvm::raw_fd_ostream& operator<<(llvm::raw_fd_ostream&, const TransRelationDB&);
}

#endif
