// Copyright 2022 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <stdio.h>

void call_my_int() asm("call_my_int");
void call_my_int() { printf("Some of the out put\n"); }