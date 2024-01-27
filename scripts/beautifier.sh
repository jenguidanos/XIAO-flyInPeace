#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SCRIPT_NAME="$( basename "${BASH_SOURCE[0]}" )"
EXECUTION_DIR="$( pwd )"

############################################################################

WORK_PATH="$1"

if [[ -z $1 ]]
   then
      echo "Please, introduce the path to the code:"
      echo "       $ ./$script_name relative_or_abs_path_to_code"
      exit 1
   else
      echo "WE ARE GOING TO BEAUTIFY C/C++ FILES INSIDE '$1'"
fi

if ! command -v clang-format &> /dev/null
then
    echo "No clang-format installed on your system please execute this command:"
    echo "sudo apt install clang-format"
    exit 1
fi

# checks absolute path
if [[ $WORK_PATH != /* ]]; then
    WORK_PATH=${EXECUTION_DIR}/${WORK_PATH}
fi

if [[ ! -d "$WORK_PATH" ]]; then
    echo "Directory doesn't exist"
    exit 1
fi

mapfile -t FILES < <( find "${WORK_PATH}" -type f )

echo "BEAUTIFYING FILES:"

for i in "${FILES[@]}"; do :
    filename=$(basename -- "$i")
    if [[ -f "${i}" &&  ${filename##*.} =~ ^(C|c|c++|CPP|cpp|cxx|H|h|hh|hpp|hxx|inc)$ ]]; then
        echo "checking ${i}..."
        echo "clang-format --style=microsoft -i ${i}"
        clang-format --style=microsoft -i ${i}

	fi
done