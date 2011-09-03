// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metatest/has_type.hpp>

#include "common.hpp"
 
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector_c.hpp>

using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::letter;
using mpllibs::metaparse::start;

using boost::mpl::equal;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;
using boost::mpl::vector_c;
using boost::mpl::list;
using boost::mpl::size;

namespace
{ 
  typedef any<letter> any_letter;

  typedef has_type<any_letter> test_has_type;

  typedef
    equal<get_result<apply_wrap2<any_letter, str_, start> >::type, list<> >
    test_empty_input;
  
  typedef
    equal<get_result<apply_wrap2<any_letter, chars0, start> >::type, list<> >
    test0;
  
  typedef
    equal<
      get_result<apply_wrap2<any_letter, chars1, start> >::type,
      vector_c<char, 'h'>
    >
    test1;
  
  typedef
    equal<
      get_result<apply_wrap2<any_letter, chars2, start> >::type,
      vector_c<char, 'h', 'e'>
    >
    test2;
  
  typedef
    equal<
      get_result<apply_wrap2<any_letter, chars3, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
    test3;
  
  typedef
    equal<
      get_result<apply_wrap2<any_letter, chars4, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l'>
    >
    test4;
  
  typedef
    equal<
      get_result<apply_wrap2<any_letter, chars5, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l', 'o'>
    >
    test5;
  
  typedef
    equal_to<
      size<get_result<apply_wrap2<any_letter, chars3, start> >::type>::type,
      int3
    >
    test_length;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test1)
MPLLIBS_ADD_TEST(suite, test2)
MPLLIBS_ADD_TEST(suite, test3)
MPLLIBS_ADD_TEST(suite, test4)
MPLLIBS_ADD_TEST(suite, test5)
MPLLIBS_ADD_TEST(suite, test_length)
