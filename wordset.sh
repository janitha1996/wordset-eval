#!/usr/bin/bash

declare -A WORDSET
hits=0
errors=0

while read -r cmd word; do
    case "$cmd" in
        I)
            WORDSET["$word"]=1
            echo "ok"
            ;;
        Q)
            if [[ ${WORDSET["$word"]+_} ]]; then
                echo "y"
                ((hits++))
            else
                echo "n"
            fi
            ;;
        S)
            case "$word" in
                count) echo "${#WORDSET[@]}" ;;
                hits) echo "$hits" ;;
                errors) echo "$errors" ;;
                *) echo "error" >&2; ((errors++)) ;;
            esac
            ;;
        C)
            if [[ "$word" == "all" ]]; then
                WORDSET=()
                echo "ok"
            else
                echo "error" >&2
                ((errors++))
            fi
            ;;
        *)
            echo "error" >&2
            ((errors++))
            ;;
    esac
done
