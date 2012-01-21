// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/one_char_except.hpp>

#include "common.hpp"

namespace
{
  typedef mpllibs::metaparse::one_char_except<char_0, char_1> oc;
}

#define TEST_NAME test_one_char_except

#include "one_char_except_test.hpp"


