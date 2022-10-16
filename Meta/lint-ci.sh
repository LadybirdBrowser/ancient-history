#!/usr/bin/env bash

set -e

script_path=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
cd "${script_path}/.." || exit 1

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

FAILURES=0

set +e

for cmd in \
        Meta/check-newlines-at-eof.py \
        Meta/check-style.py; do
    echo "Running ${cmd}"
    if time "${cmd}" "$@"; then
        echo -e "[${GREEN}OK${NC}]: ${cmd}"
    else
        echo -e "[${RED}FAIL${NC}]: ${cmd}"
        ((FAILURES+=1))
    fi
done

echo "Running Meta/lint-clang-format.sh"
if time Meta/lint-clang-format.sh --overwrite-inplace "$@" && git diff --exit-code; then
    echo -e "[${GREEN}OK${NC}]: Meta/lint-clang-format.sh"
else
    echo -e "[${RED}FAIL${NC}]: Meta/lint-clang-format.sh"
    ((FAILURES+=1))
fi

exit "${FAILURES}"
