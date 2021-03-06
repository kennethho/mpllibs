#ifndef MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP
#define MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  /*
   * Either monad for testing
   */
  MPLLIBS_DEFINE_TAG(either_tag)
  MPLLIBS_DEFINE_TAG(left_tag)
  MPLLIBS_DEFINE_TAG(right_tag)

  typedef either_tag either;
  
  template <class T>
  struct left
  {
    typedef left_tag tag;
    typedef T value;
    typedef left type;
  };
  
  template <class T>
  struct right
  {
    typedef right_tag tag;
    typedef T value;
    typedef right type;
  };
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, left, "left")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, right, "right")

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<left_tag, left_tag>
    {
      template <class A, class B>
      struct apply :
        boost::mpl::equal_to<typename A::value, typename B::value>
      {};
    };

    template <>
    struct equal_to_impl<right_tag, right_tag> :
      equal_to_impl<left_tag, left_tag>
    {};

    template <>
    struct equal_to_impl<right_tag, left_tag>
    {
      template <class A, class B>
      struct apply : boost::mpl::identity<boost::mpl::false_>
      {};
    };
    
    template <>
    struct equal_to_impl<left_tag, right_tag> :
      equal_to_impl<right_tag, left_tag>
    {};
  }
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<either_tag> : monad_defaults<either_tag>
    {
      struct return_
      {
        typedef return_ type;
        
        template <class T>
        struct apply : right<T> {};
      };
      
      struct bind
      {
        typedef bind type;
        
        template <class A, class F>
        struct apply :
          boost::mpl::if_<
            typename boost::is_same<
              right_tag,
              typename boost::mpl::tag<A>::type
            >::type,
            boost::mpl::apply<F, A>,
            A
          >::type
        {};
      };
    };
  }
}

#endif


