/* Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm, Sam Seng

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license.
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "grading/TestCase.h"

const std::string id = "lab1";
const std::string name = "Getting Started";
const std::string due_date = "2014-08-27 11:59:59.0";

// Submission parameters
const int max_submissions = 20;
const int submission_penalty = 5;

// Compile-time parameters
const int max_clocktime = 2;		// in seconds
const int max_cputime = 2;			// in seconds
const int max_output_size = 100;	// in KB
	// OTHERS?

// Grading parameters
const int total_pts = 20;
const int auto_pts = 20;
const int ta_pts = 0;
const int extra_credit_pts = 2;

// File directories

// input files directory
const char* input_dir = "test_input/lab1/";
// expected output files directory
const char* expected_out_dir = "test_output/lab1/";

// Test cases
const int num_testcases = 9;

TestCase testcases[num_testcases] = {

/************* README AND COMPILATION *****************/

  TestCase::MakeFileExists(
	"README",
	"README.txt",
	TestCasePoints(2)
),
  TestCase::MakeCompilation(
	"Compilation",
	"a.out",		// name of .exe created by student
	TestCasePoints(3)
),

/******************** TEST CASES **********************/
TestCase::MakeTestCase(
	 "non leap year test case",  // title
	 "./a.out",                  // details
	 "./a.out <nonleapyear.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test1_output.txt",  // expected output
	 TestCasePoints(5),
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),
TestCase::MakeTestCase(
	 "leap year test case",  // title
	 "./a.out",                  // details
	 "./a.out <leapyear.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test2_output.txt",  // expected output
	 TestCasePoints(5),
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),
TestCase::MakeTestCase(
	 "corner case A test case",  // title
	 "./a.out",                  // details
	 "./a.out <corner_case_A.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test3_output.txt",  // expected output
	 TestCasePoints(2),
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),
TestCase::MakeTestCase(
	 "corner case B test case",  // title
	 "./a.out",                  // details
	 "./a.out <corner_case_B.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test4_output.txt",  // expected output
	 TestCasePoints(2),
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),
TestCase::MakeTestCase(
	 "corner case C test case",  // title
	 "./a.out",                  // details
	 "./a.out <corner_case_C.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test5_output.txt",  // expected output
	 TestCasePoints(1),
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),



TestCase::MakeTestCase(
	 "error case A test case",  // title
	 "./a.out",                  // details
	 "./a.out <error_case_A.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test6_output.txt",  // expected output
	 TestCasePoints(1,false,true),	  // non hidden, extra credit
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
	 ),

TestCase::MakeTestCase(
	 "error case B test case",  // title
	 "./a.out",                  // details
	 "./a.out <error_case_B.txt", // 1> cout.txt 2> cerr.txt",                  // command
	 "cout.txt",		     // output (STDOUT)
	 "STDOUT",                   // output description
	 "test7_output.txt",  // expected output
	 TestCasePoints(1,false,true),	// non hidden, extra credit
	WARN_IF_NOT_EMPTY,		// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,		// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	&myersDiffbyLinesByChar		// compare function [V]
)

};


#endif
