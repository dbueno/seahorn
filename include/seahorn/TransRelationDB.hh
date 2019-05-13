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
    auto& os = std::cout;
    for (auto& t : getTransitions()) {
      os << "transition thing: ";
      t.first->Print(os);
      os << "\nvalue:\n";
      for (auto& c : t.second) {
        c->Print(os);
        os << "\n";
        std::flush(os);
        //solver.assertExpr(c);
      }
      os << "\n";
    }

    for (auto& l : m_locations) {
      l->Print(os);
        os << "\n";
        std::flush(os);
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
