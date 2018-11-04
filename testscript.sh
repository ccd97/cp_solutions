# Terminal colors
WHITE="\e[0m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"

# Checks
echo -e "${YELLOW}(1/4) Checking for newlines at end of all file${WHITE}"
for f in $(git diff-tree --no-commit-id --name-only -M -r HEAD); do
    if ([[ $f == *.cpp ]] || [[ $f == *.py ]])
    then
        if ! [ -z "$(tail -c 1 "$f")" ]
        then
            echo -e "${RED}No newline at end of file - $f${WHITE}"
            exit 1
        fi
    fi
done

echo -e "${YELLOW}(2/4) Checking for trailing whitespaces${WHITE}"
for f in $(git diff-tree --no-commit-id --name-only -M -r HEAD); do
    if ([[ $f == *.cpp ]] || [[ $f == *.py ]])
    then
        if grep -rli '[[:blank:]]$' $f
        then
            echo -e "${RED}Trailing whitespaces - $f${WHITE}"
            exit 1
        fi
    fi
done

echo -e "${YELLOW}(3/4) Compiling python files${WHITE}"
for f in $(git diff-tree --no-commit-id --name-only -M -r HEAD); do
    if [[ $f == *.py ]]
    then
        echo "Compiling - $f"
        if ! python3 -c "import py_compile; py_compile.compile('$f', doraise=True)"
        then
            echo -e "${RED}Error compiling file - $f${WHITE}"
            exit 1
        fi
    fi
done

echo -e "${YELLOW}(4/4) Compiling C++ files${WHITE}"
for f in $(git diff-tree --no-commit-id --name-only -M -r HEAD); do
    if [[ $f == *.cpp ]]
    then
        echo "Compiling - $f"
        if ! g++ -pipe -Wfatal-errors $f
        then
            echo -e "${RED}Error compiling file - $f${WHITE}"
            exit 1
        fi
    fi
done

echo -e "${GREEN}Sucessfully done ${WHITE}"
