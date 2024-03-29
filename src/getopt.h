/*****************************************************************************
* getopt.h - competent and free getopt library.
* $Header: /home/ubuntu/cvs/cvsroot/vpcs/getopt.h,v 1.1 2007-06-12 13:17:40 admin Exp $
*
* Copyright (c)2002-2003 Mark K. Kim
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*   * Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*
*   * Neither the original author of this software nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
* THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*/

#ifndef _GETOPT_H_
#define _GETOPT_H_

#ifdef __cplusplus
extern "C"
{
#endif

	extern char *optarg;
	extern int optind;
	extern int opterr;
	extern int optopt;

//linux 不需要getopt() 特殊照顾, freebsd 需要, 这里将#ifndef 改为#ifdef (否则linux 编译不通过)
//如果freebsd 也更新了getopt() 函数, 那么这一句可以完全删掉(整个#ifndef 删掉)
#ifdef FreeBSD
	int getopt (int argc, char **argv, char *optstr);
#endif

	int arg_to_int (const char *arg, int min, int max, int defalt);

#ifdef __cplusplus
}
#endif

#endif													/* GETOPT_H_ */

/* vim:ts=3
*/
