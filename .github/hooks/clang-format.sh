#!/bin/bash
# Copyright 2021 Practically.io All rights reserved
#
# Lint the staged files with clang-format
#
# Example hook via conventional-tools as a pre-commit hook
# pre-commit:
#   - $(git rev-parse --show-toplevel)/.gitlab/hooks/clang-format.sh
set -e

COMMAND="clang-format --dry-run --Werror"

if [[ "$1" = "--fix" ]]; then
    COMMAND="clang-format -i"
	shift
fi

# Configure the files you want to be included licence header in
files="$@"
if [[ -z "$files" ]]; then
	files=$(git diff --cached --name-only --diff-filter=ACMR "*.cpp" "*.hpp")
fi

# Test for noop
if [ -z "$files" ]; then exit 0; fi

$COMMAND $files
