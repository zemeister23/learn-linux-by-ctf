#!/bin/bash
if [ "$PROMPT_CHALLENGE" = "1" ]; then
	cat -n $HOME/.description
fi

export PROMPT_CHALLENGE="1"
