#!/bin/bash
if [ "$PROMPT_CHALLENGE" = "1" ]; then
	cat -p $HOME/.description
fi

export PROMPT_CHALLENGE="1"
