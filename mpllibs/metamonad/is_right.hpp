#ifndef MPLLIBS_METAMONAD_IS_RIGHT_HPP
#define MPLLIBS_METAMONAD_IS_RIGHT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/right.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct is_right :
      boost::is_same<
        typename boost::mpl::tag<typename T::type>::type,
        right_tag
      >
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::is_right,
  "is_right"
)

#endif

