#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
TEST_DIR="${SCRIPT_DIR}/.."
PROJECT_DIR="${SCRIPT_DIR}/../.."
GOLDEN_DIR="${TEST_DIR}/goldens/draw"
TEST_OUT_DIR="${TEST_DIR}/out/draw"
INPUTS_DIR="${TEST_DIR}/inputs/draw"
DRAW_BIN="${PROJECT_DIR}/bin/draw"

mkdir -p "${TEST_OUT_DIR}" 2>/dev/null

# $1 testName
# $2 inputFile
# $3 goldenFile
# $4 angle
function runTest() {
  ((testsRun++));
  [[ $# -ne 4 ]] && return 1;
  local testName="$1";
  local inputFile="${INPUTS_DIR}/$2";
  local testOutFile="${TEST_OUT_DIR}/$3";
  local goldenFile="${GOLDEN_DIR}/$3";
  local angle="$4"
  printf "Running test %s..." "${testName}";
  if ! cat "${inputFile}" | "${DRAW_BIN}" 500 500 "${angle}"> "${testOutFile}"; then
    printf "FAILURE! %s returned with non-zero exit status.\n" \
      "$(basename "${DRAW_BIN}")";
    return 1;
  fi
  if diff -q "${testOutFile}" "${goldenFile}"; then
    ((testsSucceeded++));
    printf "SUCCESS\n";
    return 0;
  else
    printf "FAILURE! %s does not match %s\n" "${testOutFile}" "${goldenFile}";
    return 1;
  fi
}

testsRun=0
testsSucceeded=0
printf "Running draw tests...\n" "${testsSucceeded}" "${testsRun}"
for file in "${INPUTS_DIR}"/*.input; do
  testName="$(basename "${file}")"
  runTest "${testName%.input}" "${testName}" "${testName/.input/.golden}" 90
done
printf "Finished draw tests. %u / %u tests succeeded.\n" "${testsSucceeded}" "${testsRun}"
