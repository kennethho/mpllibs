// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/if.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_if)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::if_;
  using mpllibs::metaparse::digit;
  using mpllibs::metaparse::start;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  meta_require<
    has_type<if_<digit, int11, int13> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<
      get_result<apply_wrap2<if_<digit, int11, int13>, str_1, start> >::type,
      int11
    >
  >(MPLLIBS_HERE, "test_true");
    
  meta_require<
    equal_to<
      get_result<apply_wrap2<if_<digit, int11, int13>, str_a, start> >::type,
      int13
    >
  >(MPLLIBS_HERE, "test_false");
}


