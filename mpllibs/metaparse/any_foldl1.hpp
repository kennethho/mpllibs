#ifndef MPLLIBS_METAPARSE_ANY_FOLDL1_HPP
#define MPLLIBS_METAPARSE_ANY_FOLDL1_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any_foldl.hpp>

#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class ForwardOp>
    struct any_foldl1
    {
      typedef any_foldl1 type;
    
      template <class S, class Pos>
      struct apply :
        boost::mpl::if_<
          is_error<boost::mpl::apply<P, S, Pos> >,
          P,
          any_foldl<P, State, ForwardOp>
        >::type::template apply<S, Pos>
      {};
    };
  }
}

#endif

