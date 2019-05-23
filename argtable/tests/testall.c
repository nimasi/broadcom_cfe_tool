/*******************************************************************************
 * This file is part of the argtable3 library.
 *
 * Copyright (C) 2013-2019 Tom G. Huang
 * <tomghuang@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of STEWART HEITMANN nor the  names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL STEWART HEITMANN BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include <stdio.h>

#include "CuTest.h"

CuSuite* get_arglit_testsuite();
CuSuite* get_argstr_testsuite();
CuSuite* get_argint_testsuite();
CuSuite* get_argdate_testsuite();
CuSuite* get_argdbl_testsuite();
CuSuite* get_argfile_testsuite();
CuSuite* get_argrex_testsuite();
CuSuite* get_argdstr_testsuite();
CuSuite* get_argcmd_testsuite();

#ifndef ARGTABLE3_TEST_PUBLIC_ONLY
CuSuite* get_arghashtable_testsuite();
#endif

void RunAllTests(void) {
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, get_arglit_testsuite());
    CuSuiteAddSuite(suite, get_argstr_testsuite());
    CuSuiteAddSuite(suite, get_argint_testsuite());
    CuSuiteAddSuite(suite, get_argdate_testsuite());
    CuSuiteAddSuite(suite, get_argdbl_testsuite());
    CuSuiteAddSuite(suite, get_argfile_testsuite());
    CuSuiteAddSuite(suite, get_argrex_testsuite());
    CuSuiteAddSuite(suite, get_argdstr_testsuite());
    CuSuiteAddSuite(suite, get_argcmd_testsuite());
#ifndef ARGTABLE3_TEST_PUBLIC_ONLY
    CuSuiteAddSuite(suite, get_arghashtable_testsuite());
#endif

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void) {
    RunAllTests();
    return 0;
}
