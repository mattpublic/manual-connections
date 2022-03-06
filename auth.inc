# source this script to set PIA_USER and PIA_PASS from AUTH_FILE
if [[ -e $AUTH_FILE ]]; then
  authFileLen=$(wc -l "$AUTH_FILE")
  if [[ $authFileLen != 2 ]]; then
    echo This script will grab your PIA username from the first
    echo -e line of the file specified by "${RED}AUTH_FILE${NC}", and your
    echo PIA password from the last line.
    echo
    echo -e Your current file \""${GREEN}$AUTH_FILE${NC}"\" has "${GREEN}$authFileLen${NC}" lines.
  fi
  if [[ ! $PIA_USER ]]; then
    PIA_USER=$(head -1 "$AUTH_FILE")
  fi
  if [[ ! $PIA_PASS ]]; then
    PIA_PASS=$(tail -1 "$AUTH_FILE")
  fi
fi
