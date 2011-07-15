#ifndef MPLLIBS_METAMONAD_IS_LEFT_HPP
#define MPLLIBS_METAMONAD_IS_LEFT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/left.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct is_left :
      boost::is_same<
        typename boost::mpl::tag<typename T::type>::type,
        left_tag
      >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "is_left<";
          mpllibs::metatest::to_stream<T>::run(o_);
          return o_ << ">";
        }
      };
    };
  }
}

#endif

