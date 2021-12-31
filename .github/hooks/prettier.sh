#!/bin/bash
# Copyright 2021 Practically.io All rights reserved
#
# Lint the staged files with phpcs
#
# Example hook via conventional-tools as a pre-commit hook
# pre-commit:
#   - $(git rev-parse --show-toplevel)/.gitlab/hooks/prettier.sh
set -e

COMMAND="prettier --check"
if [[ "$1" = "--fix" ]]; then
	COMMAND="prettier --write"
	shift
fi

files="$@"
if [[ -z "$files" ]]; then
    files=$(git diff --cached --name-only --diff-filter=ACMR \
                "*.css"  \
                "*.js"   \
                "*.json" \
                "*.jsx"  \
                "*.less" \
                "*.md"   \
                "*.sass" \
                "*.scss" \
                "*.ts"   \
                "*.tsx"  \
                "*.yml")
fi

# Test for noop
if [ -z "$files" ]; then exit 0; fi

cd "$(git rev-parse --show-toplevel)"
if [ -f node_modules/.bin/prettier ]; then
    COMMAND="node_modules/.bin/$COMMAND"
fi

$COMMAND $files
