#ifdef WITH_YICES2
#pragma once

#include <gmp.h>
#include "yices.h"

#include "ufo/ExprLlvm.hpp"

//using namespace expr;

namespace seahorn {
  namespace yices {


    typedef struct {
      type_t ytype;
      bool is_array;
    } ytype_t;


    class marshal_yices {


    public:

      term_t encode_term(expr::Expr exp, std::map<expr::Expr, term_t> &cache);

      bool encode_type(expr::Expr exp, ytype_t &ytp);

      expr::Expr eval(expr::Expr expr,  expr::ExprFactory &efac, std::map<Expr, term_t> &cache, bool complete, model_t *model);



    };
  }
}


#endif
