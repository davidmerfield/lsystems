#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
TEST_DIR="${SCRIPT_DIR}/.."
PROJECT_DIR="${SCRIPT_DIR}/../.."
GOLDEN_DIR="${TEST_DIR}/goldens/lsystem"
TEST_OUT_DIR="${TEST_DIR}/out/lsystem"
RULES_DIR="${PROJECT_DIR}/data/rules"
LSYSTEM_BIN="${PROJECT_DIR}/bin/lsystem"

mkdir -p "${TEST_OUT_DIR}" 2>/dev/null

# $1 testName
# $2 goldenFile
# $3 axiom
# $4 ruleFile
# $5 iterations
function runTest() {
  ((testsRun++));
  [[ $# -ne 6 ]] || return 1;
  local testName="$1";
  local goldenFile="${GOLDEN_DIR}/$2.golden";
  local testOutFile="${TEST_OUT_DIR}/$2.golden";
  local axiom="$3";
  local ruleFile="${RULES_DIR}/$4";
  local iterations="$5";
  printf "Running test %s..." "${testName}";
  if ! ${LSYSTEM_BIN} "${axiom}" "${ruleFile}" "${iterations}" > "${testOutFile}"; then
    printf "FAILURE! %s returned with non-zero exit status." \
      "$(basename "${LSYSTEM_BIN}")"
    return 1;
  fi
  if diff -q "${testOutFile}" "${goldenFile}"; then
    ((testsSucceeded++));
    printf "SUCCESS\n";
    return 0;
  else
    printf "FAILURE! %s does not match %s" "${testOutFile}" "${goldenFile}";
    return 1;
  fi
}

testsRun=0
testsSucceeded=0
printf "Running lsystems tests...\n" "${testsSucceeded}" "${testsRun}"

runTest koch1 koch1 F koch.rule 1
runTest koch2 koch2 F koch.rule 2
runTest koch3 koch3 F koch.rule 3
runTest koch4 koch4 F koch.rule 4
runTest koch5 koch5 F koch.rule 5

runTest algae1 algae1 A koch.rule 1
runTest algae2 algae2 A koch.rule 2
runTest algae3 algae3 A koch.rule 3
runTest algae4 algae4 A koch.rule 4
runTest algae5 algae5 A koch.rule 5

runTest cantor1 cantor1 A koch.rule 1
runTest cantor2 cantor2 A koch.rule 2
runTest cantor3 cantor3 A koch.rule 3
runTest cantor4 cantor4 A koch.rule 4
runTest cantor5 cantor5 A koch.rule 5

printf "Finished lsystems tests. %u / %u tests succeeded.\n" "${testsSucceeded}" "${testsRun}"
[[ "$testsRun" -eq "$testsSucceeded" ]]
