#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_nothing.h>
#include <mpllibs/metaparse/util/make_pair.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class result>
    struct except
    {
      template <class s>
      struct apply :
        boost::mpl::eval_if<
          typename
            mpllibs::metaparse::util::is_nothing<
              boost::mpl::apply<p, s>
            >::type,
          mpllibs::metaparse::util::make_pair<boost::mpl::identity<result>, s>,
          mpllibs::metaparse::nothing
        >
      {};
    };
  }
}

#endif

