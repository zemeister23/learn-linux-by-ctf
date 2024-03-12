#!/bin/bash
if [ "$PROMPT_CHALLENGE" = "1" ]; then
	vim -m $HOME/.description
fi

export PROMPT_CHALLENGE="1"
