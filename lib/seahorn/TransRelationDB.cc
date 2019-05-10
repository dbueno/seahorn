#include "seahorn/TransRelationDB.hh"


//#include "ufo/ExprLlvm.hpp"
#include "seahorn/Support/SeaDebug.h"

#include <sstream>

namespace seahorn {

void TransRelationDB::registerLocation(Expr loc) {
  m_locations.push_back(loc);
}
  
void TransRelationDB::addTransition(Expr condition, ExprVector vals) {
  m_transitions.insert({condition, vals});
}

llvm::raw_fd_ostream& operator<<(llvm::raw_fd_ostream& os,
                                 const TransRelationDB& db) {
  //for (auto& loc : db.m_locations) {
  //  os << "Location: " << *loc;
  //}

  //for (auto& [cond, vec] : db.m_transitions) {
  //  os << "Transition:\n";
  //  os << "    " << cond << "\n";
  //  os << "    " << vec << "\n";
  //}
}

}
